#include <iostream>
#include <cmath> 
using namespace std;

int stack[100];
int top = -1;
int stackSize = 100;

void push(int x) {
    if (top < stackSize - 1) {
        top = top + 1;
        stack[top] = x;
    } else {
        cout << "Stack overflow\n";
    }
}

int pop() {
    int x = 0;
    if (top == -1) {
        cout << "Stack underflow\n";
    } else {
        x = stack[top];
        top = top - 1;
    }
    return x;
}

int applyOperator(int op1, int op2, char oper) {
    if (oper == '+') return op1 + op2;
    if (oper == '-') return op1 - op2;
    if (oper == '*') return op1 * op2;
    if (oper == '/') return op1 / op2;  
    if (oper == '^') return pow(op1, op2);
    return 0;
}

int evaluatePostfix(string expr) {
    top = -1; 
    for (int i = 0; i < expr.length(); i++)
      {
        char ch = expr[i];
        if (ch == ' ') 
          continue;

        if (ch >= '0' && ch <= '9')
        {
            push(ch - '0'); 
        } 
        else { 
            int operand2 = pop();
            int operand1 = pop();
            int result = applyOperator(operand1, operand2, ch);
            push(result);
        }
    }
    return pop(); 
}

int main() {
    string expr;
    cout << "Enter postfix expression (single-digit numbers, e.g., 23*5+): ";
    cin >> expr;

    int result = evaluatePostfix(expr);
    cout << "Result: " << result << "\n";

    return 0;
}
