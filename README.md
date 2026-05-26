# ⚡ Expression Evaluator in C++

A stack-based mathematical expression evaluator that converts **infix expressions** to **postfix (Reverse Polish Notation)
** and evaluates them — built entirely from scratch using a custom Stack implementation.

---

## 🧠 How It Works

```
Input  (Infix)  :  3 + 5 * (2 - 1)
         ↓
  Shunting Yard Algorithm
         ↓
Postfix (RPN)   :  3 5 2 1 - * +
         ↓
  Stack-based Evaluation
         ↓
Result          :  8
```

---

## 🛠️ Features

- ✅ Supports `+`, `-`, `*`, `/`, `^` (power)
- ✅ Handles parentheses `( )`
- ✅ Multi-digit and decimal numbers (e.g. `3.14 * 2`)
- ✅ Correct operator precedence and associativity
- ✅ Handles unary minus (e.g. `-3 + 5`)
- ✅ Division by zero detection
- ✅ Mismatched parenthesis detection
- ✅ Custom Stack — no STL stack used
- ✅ Full test suite with 18+ test cases

---

## 📁 Project Structure

```
expression_evaluator/
├── include/
│   ├── Stack.h          # Custom templated Stack (linked list based)
│   └── Evaluator.h      # Evaluator class declaration
├── src/
│   ├── Evaluator.cpp    # Shunting Yard + Postfix evaluation logic
│   └── main.cpp         # Interactive CLI program
├── tests/
│   └── test_evaluator.cpp  # Full test suite
├── Makefile
└── README.md
```

---

## 🚀 How to Run

### Build & Run
```bash
make run
```

### Run Tests
```bash
make test
```

### Manual Build
```bash
g++ -std=c++17 -I include src/Evaluator.cpp src/main.cpp -o expression_evaluator
./expression_evaluator
```

---

## 💻 Example Session

```
>> 3 + 5
   Postfix  : 3 5 +
   Result   : 8.0000

>> 3 + 5 * (2 - 1)
   Postfix  : 3 5 2 1 - * +
   Result   : 8.0000

>> 2 ^ 10
   Postfix  : 2 10 ^
   Result   : 1024.0000

>> 10 / 0
   Error    : Division by zero
```

---

## 📚 Concepts Demonstrated

| Concept | Where Used |
|---|---|
| Stack (custom, templated) | `include/Stack.h` |
| Shunting Yard Algorithm | `src/Evaluator.cpp` |
| Operator precedence & associativity | `precedence()` function |
| OOP & separation of concerns | Header + Source split |
| Error handling (`std::runtime_error`) | Throughout |
| Template programming | `Stack<T>` |

---

## 👤 Author

**Ankan Laskar** · [GitHub](https://github.com/ankanlaskar2320)

> Part of my **SDE preparation series** — building projects that directly apply Data Structures concepts.
