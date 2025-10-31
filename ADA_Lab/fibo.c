#include<stdio.h>
#include<time.h>

void fibonacci_iterative(int n) {
    long long int a = 0, b = 1;
    long long int next_term;
    if (n >= 1) {
        printf("%lld  ", a);
    }
    if (n >= 2) {
        printf("%lld  ", b);
    }
    for (int i = 2; i < n; i++) {
        next_term = a + b;
        printf("%lld  ", next_term);
        a = b;
        b = next_term;
    }
}

int main() {
    int n;
    printf("ENTER THE NUMBER OF TERMS IN FIBONACCI SERIES :");
    scanf("%d", &n);
    
    clock_t start = clock();
    fibonacci_iterative(n);
    clock_t end = clock();
    
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n THE TIME TAKEN IS : %f", time_taken);
    
    return 0;
}