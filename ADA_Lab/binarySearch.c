#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int compare(const void *a,const void *b){
    return ((int)a-(int)b);
}

int binary_search(int*arr,int n,int key){
    int low=0,high=n-1;

    while(low<=high){
        int mid =low +(high-low)/2;
        if(key==arr[mid]){
            return mid;
        }
        else if(key<arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return -1;
    
}

void random_array(int *arr,int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }

}
int main()
{
    int n, key, pos;
    printf("Enter the number of elements you want in an array");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if(arr==NULL){
        printf("Memory is not allocated to array");
        return -1;
    }
     random_array(arr,n);
    printf("Enter the element you want to search");
    scanf("%d", &key);
    qsort(arr,n,sizeof(int),compare);
      
    clock_t start = clock();
    for(int i=0;i<10000;i++){
          pos = binary_search(arr, n, key);
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
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC/1000.0;


    printf("TIME TAKEN IS : %f", time_taken);
    free(arr);

    return 0;
}