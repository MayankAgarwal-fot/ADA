#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_array(int *arr,int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }

}
int linearsearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, key, pos;
    printf("Enter the number of elements you want in an array");
    scanf("%d", &n);
    if(n<10){ 
        return -1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if(arr==NULL){
        printf("Memory is not allocated to array");
        return -1;
    }
    printf("Enter the element you want to search: ");
    scanf("%d", &key);
    random_array(arr,n);

    clock_t start = clock();

    for(int i=0;i<10000;i++){
        pos = linearsearch(arr, n, key);
    }
  
    clock_t end = clock();

    if (pos != -1)
    {
        printf("Element is found at %d th index\n", pos);
    }
    else
    {
        printf("Element not found.\n");
    }
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC/100.0;


    printf("TIME TAKEN IS : %f", time_taken);
    free(arr);

    return 0;
}