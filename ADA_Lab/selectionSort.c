#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Selection Sort function
// Sorts the array by repeatedly finding the minimum element
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    
 
    for (i = 0; i < n - 1; i++) {
        // Assume the first element is the minimum
        min_idx = i;
        
        // Find the actual minimum element in the remaining unsorted array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update index of the minimum element
            }
        }
        
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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

    printf("Selection Sort Time Complexity Analysis\n");
    printf("n,time_taken\n"); 

    for (int i = 0; i < num_values; i++) {
        int n = n_size[i]; 
        int *arr = (int *)malloc(n * sizeof(int));  
        if (arr == NULL) {
            printf("Memory allocation failed for n=%d\n", n);
            continue; // Skip this test case if memory allocation fails
        }

        generateRandomArray(arr, n); 

      
        clock_t start = clock(); // Start time 
        selectionSort(arr, n); 
        clock_t end = clock(); // End time
       

        // Calculate time 
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("The time taken by %d number of input is: %f\n", n, time_taken);

        free(arr); 
    }

    return 0;
}