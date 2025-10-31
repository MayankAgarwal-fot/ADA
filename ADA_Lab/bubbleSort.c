#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble Sort function

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        // After each pass, the largest element among the unsorted part moves to the end
        for (j = 0; j < n - i - 1; j++) {
           
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Generate a random number between 0 and 99,999
    }
}

int main() {


    int n_size[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    int num_values = sizeof(n_size) / sizeof(n_size[0]);

    printf("Bubble Sort Time Complexity Analysis\n");
    printf("n,time_taken\n"); // Print header for CSV output

    for (int i = 0; i < num_values; i++) {
        int n = n_size[i]; 
        int *arr = (int *)malloc(n * sizeof(int)); 
        if (arr == NULL) {
            printf("Memory allocation failed for n=%d\n", n);
            continue; // Skip this test case if memory allocation fails
        }

        generateRandomArray(arr, n); 

    
        clock_t start = clock();  // Start time 
        bubbleSort(arr, n);
        clock_t end = clock();  // End time 
       

        // Calculate time 
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("The time taken by %d number of input is: %f\n", n, time_taken);

        free(arr); // Free allocated memory
    }

    return 0;
}