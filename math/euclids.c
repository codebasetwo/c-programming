#include<stdio.h>
int euclids_gcd(int a, int b);
int euclids_gcd_clean(int a, int b);
int euclids_gcd_recursive(int a, int b);

int main(void) {
    int a = 105, b = 350;
    int gcd = euclids_gcd(a, b);
    int gcd_clean = euclids_gcd_clean(a, b);
    int gcd_recursion = euclids_gcd_recursion(a, b);
    printf("GCD of %d and %d is %d\n", a, b, gcd);
    printf("GCD (clean) of %d and %d is %d\n", a, b, gcd_clean);
    printf("GCD (recursion) of %d and %d is %d\n", a, b, gcd_recursion);
    return 0;
}

int euclids_gcd_recursive(int a, int b) {
    if (b == 0) return a;
    return euclids_gcd(b, a % b);
    // if (b == 0) ? a : euclids_gcd(b, a % b);
}

int euclids_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int euclids_gcd_clean(int a, int b) { // O(log(min(a, b)))
    int dividend = a >= b ? a: b;
    int divisor = a < b ? a: b;
    while (divisor != 0) {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    return dividend;
}