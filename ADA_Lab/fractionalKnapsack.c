#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

void merge(Item arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    Item *L = (Item *)malloc(n1 * sizeof(Item));
    Item *R = (Item *)malloc(n2 * sizeof(Item));
    if (L == NULL || R == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
     
        if (L[i].ratio >= R[j].ratio) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(Item arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

double fractionalKnapsack(int capacity, Item items[], int n) {
   
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    mergeSort(items, 0, n - 1);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].ratio * remainingCapacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));
    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
  
    for (int i = 0; i < n; i++) {
         items[i].weight = rand() % 20 + 1;
          items[i].value = rand() % 20 + 1;
         if(n < 20){
 printf("Item %d: Weight = %d, Value = %d\n", i + 1, items[i].weight, items[i].value);
      }
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    clock_t start = clock();
    double maxValue = fractionalKnapsack(capacity, items, n);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Maximum value in fractional knapsack = %.2f\n", maxValue);
    printf("\nTime taken: %.6f seconds\n", time_spent);

    free(items);
    items = NULL;

    return 0;
}

