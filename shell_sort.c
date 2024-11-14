#include <stdio.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap) {
                temp = arr[j];
                arr[j] = arr[j - gap];
                arr[j - gap] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 12, 34, 54, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    shellSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}