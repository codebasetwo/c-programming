#include<stdio.h>

int Fib[51];
int fibonacci_recursive(int n) {// O(2^n) time complexity, O(n) space complexity
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2); // use memoization to optimize this function
}

int fibonacci_recursive_mem(int n) {// O(2^n) time complexity, O(n) space complexity
    if (n <= 1) {
        return n;
    }
    if (Fib[n] != -1) {
        return Fib[n];
    }
    Fib[n] = fibonacci_recursive_mem(n - 1) + fibonacci_recursive_mem(n - 2); // use memoization to optimize this function
    return Fib[n];
}

int fibonacci_iterative(int n) {// O(n) time complexity, O(1) space complexity
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        Fib[i] = -1;
    }
    int fib = fibonacci_recursive(n);
    int fib_mem = fibonacci_recursive_mem(n);
    int fib_iter = fibonacci_iterative(n);
    printf("Fibonacci nth term is %d\n", fib_iter);
    printf("Recursive: %d\n", fib);
    printf("Recursive with memoization: %d\n", fib_mem);
}