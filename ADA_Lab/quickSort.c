#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//   swap function 
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
// It places the pivot element at its correct position and

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as the pivot
    int i = (low - 1);      // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
       
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(&arr[i], &arr[j]); // Swap 
        }
    }
    // Place the pivot in its correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Return the partition index
}

// Quick Sort function using divide and conquer
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Get the partition index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate an array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Generate a random number between 0 and 99,999
    }
}

int main() {
    //  the array sizes (n) 
    int n_size[] = {10, 50, 100, 500, 1000, 3000, 5000, 6000, 8000};
    int num_values = sizeof(n_size) / sizeof(n_size[0]);

    printf("Quick Sort Time Complexity Analysis\n");
    printf("n,time_taken\n"); 

    for (int i = 0; i < num_values; i++) {
        int n = n_size[i]; 
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed for n=%d\n", n);
            continue; // Skip to the next iteration if memory allocation fails
        }

        generateRandomArray(arr, n); // Fill the array with random numbers

       
        clock_t start = clock(); // Start  time
        quickSort(arr, 0, n - 1);
        clock_t end = clock();// End  time
        

        // Calculate time taken 
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("The time taken by %d number of input is: %f\n", n, time_taken);

        free(arr);
    }

    return 0;
}