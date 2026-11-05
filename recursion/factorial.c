#include<stdio.h>

typedef unsigned long long int ubigint;

ubigint factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return  n * factorial(n - 1);
}

ubigint factorial_iterative(int n) {
    ubigint result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n = 6;
    printf("%d! =  %lld\n", n, factorial(n));
    printf("%d! =  %lld\n", n, factorial_iterative(n));
}



