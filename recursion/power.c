#include<stdio.h>

int power(int base, int exp) {// O(n) time complexity, O(n) space complexity
    if (exp == 0) return 1;
    else return base * power(base, exp-1);
}

int power_iterative(int base, int exp) { // O(n) time complexity, O(1) space complexity
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int power_optimized(int base, int exp) { // O(log n) time complexity, O(log n) space complexity
    if (exp == 0) return 1;
    int half = power_optimized(base, exp / 2);
    if (exp % 2 == 0) {
        return half * half;
    } else {
        return base * half * half;
    }
}

int mod_optimized(int base, int exp, int mod) { // O(log n) time complexity, O(log n) space complexity
    if (exp == 0) return 1;
    if (exp % 2 == 0) {
        int result = mod_optimized(base, exp / 2, mod);
        return (result * result) % mod;
    } else {
        return ((base % mod) * mod_optimized(base, exp-1, mod)) % mod;
    }
}

int main() {
    int base, exp;
    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exp);

    printf("modular exponent %d\n", mod_optimized(base, exp, 7));
    printf("Recursive Power: %d\n", power(base, exp));
    printf("Iterative Power: %d\n", power_iterative(base, exp));
    printf("Optimized Power: %d\n", power_optimized(base, exp));


    return 0;
}

