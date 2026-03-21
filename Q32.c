/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 // Define maximum size of the stack

// Define the structure for the stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

//Function to initialize the stack

void initstack(struct Stack*s ){
    s -> top = -1;
}

void push(struct Stack *s, int value){
    if(s->top <MAX_SIZE-1){
        s->items[++s->top] = value;
    }
        else{
            printf("Overflow");
        }
    }

int pop(struct Stack *s){
    if(s->top>=0){
        return s->items[s->top--];
    }
    else{
        printf("Underflow");
        return -1;
     }
}


int main(){
    struct Stack s;
    initnstack(&s);

    int m,n,value;

    printf("Enter the number of elements to push: ");
    scanf("%d", &n);
    printf("Enter the elements to push: ");
    for(int i=0; i<n; i++){
        scanf("%d", &value);
        push(&s, value);
    }
    printf("Enter the number of elements to pop: ");
    scanf("%d", &m);
    printf("Popped elements: ");
    for(int i=0; i<m; i++){
        printf("%d ", pop(&s));
    }

    return 0;

}
