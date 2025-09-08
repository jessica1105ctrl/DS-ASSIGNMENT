#include <iostream>
#include <string>
using namespace std;
char stack[100];
int top = -1;
int stackSize = 100;

void push(char c) {
    if (top < stackSize - 1) {
        top = top + 1;
        stack[top] = c;
    } else {
        cout << "Stack overflow\n";
    }
}

char pop() {
    char c = ' ';
    if (top == -1) {
        cout << "Stack underflow\n";
    } else {
        c = stack[top];
        top = top - 1;
    }
    return c;
}

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string expression) {
    top = -1; // reset stack for each expression
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                return false; // no matching opening bracket
            }
            char open = pop();
            if (!isMatching(open, ch)) {
                return false;
            }
        }
    }
    if (top == -1) return true; 
    else return false;           
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr)) {
        cout << "Balanced\n";
    } else {
        cout << "Not balanced\n";
    }

    return 0;
}
