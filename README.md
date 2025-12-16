# Valid Parentheses

This repository contains a C implementation to solve the **Valid Parentheses** problem using a stack-based approach.

---

## 🧩 Problem Statement

Given a string `s` containing only the characters `(`, `)`, `{`, `}`, `[`, `]`, determine whether the input string is valid.

### A string is considered valid if:
- Open brackets are closed by the **same type** of brackets.
- Open brackets are closed in the **correct order**.
- Every closing bracket has a corresponding opening bracket.

---

## ✅ Examples

| Input     | Output |
|----------|--------|
| `()`     | true   |
| `()[]{} | true   |
| `(]`     | false  |
| `([])`   | true   |
| `([)]`   | false  |

---

## 🛠 Approach

- Use a **stack** to store opening brackets.
- Traverse the string character by character:
  - Push opening brackets onto the stack.
  - For closing brackets:
    - Check if stack is empty → invalid.
    - Pop the top element and verify matching pair.
- At the end, if the stack is empty → valid string.

---

## ⏱ Time & Space Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 C Implementation

```c
bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 == 1) {
        return false;
    }

    char stack[100005];
    int top = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[top++] = c;
        } else {
            if (top == 0) {
                return false;
            }

            char t = stack[--top];
            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                return false;
            }
        }
    }

    return top == 0;
}
