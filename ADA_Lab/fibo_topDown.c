#include <stdio.h>
#include<time.h>


long long  nthFibonacciUtil(int n, int memo[]) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = nthFibonacciUtil(n - 1, memo) 
                   + nthFibonacciUtil(n - 2, memo);
    return memo[n];
}
long long  nthFibonacci(int n) {
    int memo[n+1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    return nthFibonacciUtil(n, memo);
}


int main() {
    int n;
  printf("ENTER THE POSITION:");
    scanf("%d",&n);
    clock_t start =clock();
    long long result;
    for(int i=0;i<1000;i++){
         result = nthFibonacci(n);
    }

    clock_t end = clock();
    printf("%lld\n", result);
    double time_taken = (double)(end-start)/CLOCKS_PER_SEC/1000;

    printf("THE TIME TAKEN IS :%f",time_taken);

    return 0;
}