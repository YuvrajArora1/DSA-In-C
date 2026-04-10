/*Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, 
then repeatedly extract the maximum element and place it at the end of the array.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void maxHeapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        // Swap
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // Call max heapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n > MAX_SIZE) {
        printf("Exceeds maximum size\n");
        return 1;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}




