#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion Sort function
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];       
        j = i - 1;       
        
        // Shift elements of arr[0..i-1] that are greater than key
        // Move them one position ahead to make space for key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Place the key at its correct position
        arr[j + 1] = key;
    }
}


void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Random number between 0 and 99,999
    }
}

int main() {
 
    int n_size[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    int num_values = sizeof(n_size) / sizeof(n_size[0]);

    printf("Insertion Sort Time Complexity Analysis\n");
    printf("n,time_taken\n"); 

    for (int idx = 0; idx < num_values; idx++) {
        int n = n_size[idx];
        int *arr = (int *)malloc(n * sizeof(int)); 
        if (arr == NULL) {
            printf("Memory allocation failed for n=%d\n", n);
            continue; // Skip this iteration if memory allocation fails
        }

        generateRandomArray(arr, n);


        clock_t start = clock(); // Start time 
        insertionSort(arr, n);
        clock_t end = clock();  // End Time
        

        // Calculate time 
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("The time taken by %d number of input is: %f\n", n, time_taken);

        free(arr); 
    }

    return 0;
}