#include<stdio.h>
#include<time.h>

long long  fibonacci_recurssive(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
     return 1;
}
 return fibonacci_recurssive(n-1)+fibonacci_recurssive(n-2);
}
int main(){
    int n;
    printf("ENTER THE TERM FOR FIBONACCI SERIES:");
    scanf("%d",&n);
    clock_t start =clock();
   long long  result= fibonacci_recurssive(n);
   clock_t end= clock();

    printf("THE NUMBER AT %d TH POSITION IS: %lld",n,result);
    double time_taken =(double)(end-start)/CLOCKS_PER_SEC;

    printf("\n THE TIME TAKEN IS : %f",time_taken);

    return 0;
}