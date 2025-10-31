#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Merge function
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    // Sizes of the two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Allocate temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0; // Initial index of left subarray
    j = 0; // Initial index of right subarray
    k = left; // Initial index of merged array
    // Merge the two arrays back into arr[]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    // Free allocated memory
    free(L);
    free(R);
}
// Merge sort function
void mergeSort(int A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point
        mergeSort(A, left, mid);  // Sort first half
        mergeSort(A, mid + 1, right); // Sort second half
        merge(A, left, mid, right); // Merge the two halves
    }
}

// Function to generate a random array with values between 0 and 99,999
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Generate a random number
    }
}

int main() {
    //  different sizes of n to test
    int n_size[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000};
    int num_values = sizeof(n_size) / sizeof(n_size[0]);

    printf("n,time_taken\n"); 

    for (int i = 0; i < num_values; i++) {
        int n = n_size[i]; 
        int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory for the array
        if (arr == NULL) {
            printf("Memory allocation failed for n=%d\n", n);
            continue;
        }

        generateRandomArray(arr, n); 

        clock_t start = clock(); // Start time
        mergeSort(arr, 0, n - 1); 
        clock_t end = clock(); // End time 

        // Calculate the time taken in seconds
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("The time taken by %d number of input is: %f\n", n, time_taken); 

        free(arr); // Free allocated memory
    }
    return 0;
}