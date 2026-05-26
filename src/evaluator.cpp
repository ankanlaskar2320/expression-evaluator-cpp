#include "../include/evaluator.h"
#include "../include/stack.h"
#include <string>
#include <sstream>   // for istringstream (reading postfix token by token)
#include <cmath>     // for pow() function

// ─────────────────────────────────────────
// Remove all spaces from a string
// "3 + 5" becomes "3+5"
// ─────────────────────────────────────────
std::string evaluator::removeSpaces(std::string str) {
    std::string result = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            result = result + str[i];
        }
    }
    return result;
}

// Higher number = higher priority
int evaluator::getPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    return 0;
}

// Check if character is an operator
bool evaluator::isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

// Check if character is a digit or dot
bool evaluator::isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    if (c == '.') {
        return true;
    }
    return false;
}

double evaluator::calculate(double a, double b, char op) {
    if (op == '+') {
        return a + b;
    }
    if (op == '-') {
        return a - b;
    }
    if (op == '*') {
        return a * b;
    }
    if (op == '/') {
        if (b == 0) {
            std::cout << "Error: Division by zero\n";
            exit(1);
        }
        return a / b;
    }
    if (op == '^') {
        return pow(a, b);
    }
    return 0;
}

// ─────────────────────────────────────────
// Convert Infix to Postfix
//
// Infix:   3 + 5 * 2
// Postfix: 3 5 2 * +
//
// Uses the Shunting Yard Algorithm:
// - Numbers go directly to output
// - Operators go to a stack
// - Higher priority operators are processed first
// ─────────────────────────────────────────
std::string evaluator::infixToPostfix(std::string expression) {

    std::string expr = removeSpaces(expression);
    stack<char> operatorStack;
    std::string postfix = "";

    int i = 0;
    while (i < expr.length()) {

        char c = expr[i];

        if (isDigit(c)) {
            // Keep reading digits until we hit a non-digit
            while (i < expr.length() && isDigit(expr[i])) {
                postfix = postfix + expr[i];
                i = i + 1;
            }
            postfix = postfix + ' ';  // add space to separate numbers
            // Don't increment i here, the loop will do it
            continue;
        }

        // If it is an opening bracket, push to stack
        if (c == '(') {
            operatorStack.push(c);
        }

        // If it is a closing bracket
        // Pop everything until we find the matching opening bracket
        else if (c == ')') {
            while (operatorStack.isEmpty() == false && operatorStack.peek() != '(') {
                postfix = postfix + operatorStack.peek();
                postfix = postfix + ' ';
                operatorStack.pop();
            }
            operatorStack.pop(); // remove the '(' from stack
        }

        // If it is an operator like +, -, *, /, ^
        else if (isOperator(c)) {

            // Pop operators from stack that have higher or equal priority
            // and add them to postfix first
            while (operatorStack.isEmpty() == false &&
                   isOperator(operatorStack.peek()) &&
                   getPrecedence(operatorStack.peek()) >= getPrecedence(c)) {

                postfix = postfix + operatorStack.peek();
                postfix = postfix + ' ';
                operatorStack.pop();
            }

            // Then push current operator to stack
            operatorStack.push(c);
        }

        i = i + 1;
    }

    // Pop any remaining operators from the stack
    while (operatorStack.isEmpty() == false) {
        postfix = postfix + operatorStack.peek();
        postfix = postfix + ' ';
        operatorStack.pop();
    }

    return postfix;
}

// ─────────────────────────────────────────
// Evaluate a Postfix expression
//
// Postfix: 3 5 2 * +
// - Read token by token
// - If number → push to stack
// - If operator → pop two numbers, calculate, push result
// ─────────────────────────────────────────
double evaluator::evaluatePostfix(std::string postfix) {

    stack<double> numberStack;

    // istringstream lets us read the postfix string word by word
    std::istringstream stream(postfix);
    std::string token;

    while (stream >> token) {

        // If the token is a single operator character
        if (token.length() == 1 && isOperator(token[0])) {
            double b = numberStack.peek();
            numberStack.pop();
            double a = numberStack.peek();
            numberStack.pop();

            double result = calculate(a, b, token[0]);
            numberStack.push(result);
        }
        else {
            // It is a number, convert string to double and push
            double number = std::stod(token);
            numberStack.push(number);
        }
    }

    // The final answer is the only element left in the stack
    return numberStack.peek();
}

// ─────────────────────────────────────────
// Main evaluate function
// Combines both steps together
// ─────────────────────────────────────────
double evaluator::evaluate(std::string expression) {
    std::string postfix = infixToPostfix(expression);
    double result = evaluatePostfix(postfix);
    return result;
}