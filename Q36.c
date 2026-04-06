/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularQueue {
    Node* front;
    Node* rear;
    int size;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

void enqueue(CircularQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->size == 0) {
        q->front = q->rear = newNode;
        newNode->next = newNode; // Point to itself
    } else {
        q->rear->next = newNode; // Link rear to new node
        q->rear = newNode; // Update rear
        q->rear->next = q->front; // Point rear to front
    }
    q->size++;
}


void dequeue(CircularQueue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = q->front;
    if (q->size == 1) {
        q->front = q->rear = NULL; // Queue becomes empty
    } else {
        q->front = q->front->next; // Move front to next node
        q->rear->next = q->front; // Update rear to point to new front
    }
    free(temp); // Free the dequeued node
    q->size--;
}


int main() {
    CircularQueue q;
    initQueue(&q);

    int n, m, value;
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);
    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    return 0;
}


