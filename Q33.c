/*
Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression*/


#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX_SIZE];
    int top = -1, j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
            postfix[j++] = token; // Add operand to postfix
        } else if (token == '(') {
            stack[++top] = token; // Push '(' to stack
        } else if (token == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--]; // Pop until '(' is found
            }
            top--; // Pop '(' from stack
        } else { // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = stack[top--]; // Pop operators with higher or equal precedence
            }
            stack[++top] = token; // Push current operator to stack
        }
    }

    while (top != -1) {
        postfix[j++] = stack[top--]; // Pop remaining operators
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}
