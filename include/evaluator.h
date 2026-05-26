#ifndef EVALUATOR_H
#define EVALUATOR_H

#include<string>

class evaluator{

public:
    //main function -> give it "3+5*2", it return 13
    double evaluate(std::string expression);

    //converts infix to postfix, "3 + 5" becomes "3 5 +""
    std::string infixToPostfix(std::string expression);

    //evaluate the postfix expression, 3 5 + return 8
    double evaluatePostfix(std::string postfix);

private:
    //returns priority of operator: * and / are higher than + and -
    int getPrecedence(char op);

    bool isOperator(char c);

    bool isDigit(char c);

    double calculate(double a, double b, char op);

    std::string removeSpaces(std::string str);
};

#endif