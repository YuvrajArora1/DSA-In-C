/* Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node representing a term in the polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertEnd(struct Node* head, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (head == NULL) {
        return newNode; // If the list is empty, the new node becomes the head
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next; // Traverse to the end of the list
    }
    current->next = newNode; // Link the last node to the new node
    return head; // Return the head of the list
}

// Function to traverse the linked list and print the polynomial
void traverseList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%dx^%d ", current->coefficient, current->exponent);
        current = current->next; // Move to the next node
    }
}

// Function to free the linked list memory
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n;
    struct Node* head = NULL;

    // Read the number of terms in the polynomial
    scanf("%d", &n);

    // Read the coefficient and exponent for each term and insert them into the list
    for (int i = 0; i < n; i++) {
        int coefficient, exponent;
        scanf("%d %d", &coefficient, &exponent);
        head = insertEnd(head, coefficient, exponent);
    }

    // Traverse the list and print the polynomial
    traverseList(head);
    
    // Free the linked list memory
    freeList(head);

    return 0;
}

