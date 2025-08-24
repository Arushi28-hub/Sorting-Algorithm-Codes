#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function using FIRST element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // First element as pivot
    int i = low + 1;       // Start from next element
    int j = high;
    
    while (i <= j) {
        // Find element greater than pivot from left
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        
        // Find element smaller than pivot from right
        while (j > low && arr[j] >= pivot) {
            j--;
        }
        
        // Swap if pointers haven't crossed
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Swap pivot with j (correct position)
    swap(&arr[low], &arr[j]);
    
    return j;  // Return partition index
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
