/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initStack(struct Stack* s) {
    s->top = NULL;
}

void push(struct Stack* s, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack underflow\n");
        return -1; // Return -1 to indicate stack is empty
    }
    struct Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* postfix) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];

        if (token >= '0' && token <= '9') {
            push(&s, token - '0'); // Convert char to int and push
        } else { // Operator
            int val2 = pop(&s);
            int val1 = pop(&s);
            int result;

            switch (token) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default: printf("Invalid operator\n"); return -1;
            }
            push(&s, result); // Push the result back to stack
        }
    }
    return pop(&s); // Final result
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    if (result != -1) {
        printf("Result: %d\n", result);
    }
    return 0;
}

