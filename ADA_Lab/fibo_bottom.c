#include <stdio.h>
#include<time.h>


long long  nthFibonacci(int n) {
    if (n <= 1) return n;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n ;
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

    printf("THE TIME TAKEN IS: %f",time_taken);
    return 0;
}