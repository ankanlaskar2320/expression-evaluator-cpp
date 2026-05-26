#include <iostream>
#include <string>
#include "../include/evaluator.h"

int main() {

    std::cout << "\n";
    std::cout << "  ╔══════════════════════════════════════╗\n";
    std::cout << "  ║     EXPRESSION EVALUATOR  v1.0       ║\n";
    std::cout << "  ║     Stack-Based · Infix to Postfix   ║\n";
    std::cout << "  ╚══════════════════════════════════════╝\n";
    std::cout << "\n";
    std::cout << "  Supports: + - * / ^ and ( )\n";
    std::cout << "  Examples: 3 + 5 * 2   or   (10 - 4) * 3\n";
    std::cout << "  Type exit to quit\n";
    std::cout << "\n";

    evaluator eval;
    std::string input;

    while (true) {

        std::cout << "  >> ";
        std::getline(std::cin, input);

        // Exit condition
        if (input == "exit" || input == "quit") {
            std::cout << "\n  Goodbye!\n\n";
            break;
        }

        // Skip empty input
        if (input == "") {
            continue;
        }

        // Try to evaluate, catch any errors
        try {
            std::string postfix = eval.infixToPostfix(input);
            double result = eval.evaluatePostfix(postfix);

            std::cout << "  Postfix : " << postfix << "\n";
            std::cout << "  Result  : " << result << "\n";
            std::cout << "\n";
        }
        catch (std::exception& e) {
            std::cout << "  Error   : " << e.what() << "\n\n";
        }
    }

    return 0;
}