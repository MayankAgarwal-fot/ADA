#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ITEMS 1500
#define MAX_CAPACITY 1500
int dp[MAX_ITEMS][MAX_CAPACITY];

int ma(int a, int b){
    return (a > b) ? a : b;
}

int knapsackMemo(int W, int weight[], int value[], int n) {
   
    if (n == 0 || W == 0) {
        return 0;
    }

   
    if (dp[n][W] != -1) {
        return dp[n][W];
    }

  
    if (weight[n - 1] > W) {
        return dp[n][W] = knapsackMemo(W, weight, value, n - 1);
    } 
   
    else {
        return dp[n][W] = ma(value[n - 1] + knapsackMemo(W - weight[n - 1], weight, value, n - 1),
                             knapsackMemo(W, weight, value, n - 1));
    }
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_ITEMS - 1) {
        printf("Invalid number of items.\n");
        return 1;
    }

    int* weight = (int*)malloc(n * sizeof(int));
    int* value = (int*)malloc(n * sizeof(int));
    if (weight == NULL || value == NULL) {
        printf("Memory allocation failed!\n");
        free(weight);
        free(value);
        return 1;
    }
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        weight[i] = rand() % 20 + 1;
        value[i] = rand() % 20 + 1;
        if (n < 20) {
            printf("Item %d: Weight = %d, Value = %d\n", i + 1, weight[i], value[i]);
        }
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    if (W <= 0 || W > MAX_CAPACITY - 1) {
        printf("Invalid knapsack capacity.\n");
        free(weight);
        free(value);
        return 1;
    }

    memset(dp, -1, sizeof(dp));
   
    clock_t start = clock();
    
  
    int result = knapsackMemo(W, weight, value, n);
    
    clock_t end = clock();

    printf("\nMaximum value (Memoization) = %d\n", result);
    printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(weight);
    free(value);

    return 0;
}
