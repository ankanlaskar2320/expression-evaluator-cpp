#include <iostream>
#include <cassert>
#include <cmath>
#include "../include/evaluator.h"

int passed = 0, failed = 0;

void test(const std::string& expr, double expected, evaluator& eval) {
    try {
        double result = eval.evaluate(expr);
        if (std::fabs(result - expected) < 0.0001) {
            std::cout << "  [PASS]  " << expr << " = " << result << "\n";
            passed++;
        } else {
            std::cout << "  [FAIL]  " << expr << " expected " << expected << " got " << result << "\n";
            failed++;
        }
    } catch (const std::exception& e) {
        std::cout << "  [ERROR] " << expr << " → " << e.what() << "\n";
        failed++;
    }
}

void testError(const std::string& expr, evaluator& eval) {
    try {
        eval.evaluate(expr);
        std::cout << "  [FAIL]  " << expr << " should have thrown\n";
        failed++;
    } catch (...) {
        std::cout << "  [PASS]  " << expr << " correctly threw error\n";
        passed++;
    }
}

int main() {
    evaluator eval;

    std::cout << "\n  ── Basic Arithmetic ──\n";
    test("3 + 5", 8, eval);
    test("10 - 4", 6, eval);
    test("6 * 7", 42, eval);
    test("15 / 3", 5, eval);

    std::cout << "\n  ── Precedence ──\n";
    test("3 + 5 * 2", 13, eval);
    test("10 - 4 * 2", 2, eval);

    std::cout << "\n  ── Parentheses ──\n";
    test("(3 + 5) * 2", 16, eval);
    test("(10 - 4) * 2", 12, eval);

    std::cout << "\n  ── Power ──\n";
    test("2 ^ 10", 1024, eval);
    test("3 ^ 3", 27, eval);

    std::cout << "\n  ── Decimals ──\n";
    test("3.5 * 2 + 1.5", 8.5, eval);

    std::cout << "\n  ── Errors ──\n";
    testError("10 / 0", eval);
    testError("(3 + 5", eval);

    std::cout << "\n  Results: " << passed << " passed, " << failed << " failed\n\n";
    return 0;
}