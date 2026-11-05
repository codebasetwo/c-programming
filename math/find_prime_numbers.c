#include <stdio.h>
#include <stdlib.h>

int *find_primes(int n, int *count_out);   // return count via pointer
int  is_prime(int n);

int main(void) {
    int n = 20;
    int count = 0;
    int *primes = find_primes(n, &count);

    if (!primes) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    for (int i = 0; i < count; i++)        // < count, not <= n
        printf("%d ", primes[i]);
    printf("\n");

    free(primes);
    return 0;
}

int *find_primes(int n, int *count_out) {
    if (n < 2) { *count_out = 0; return NULL; }

    // At most n-1 numbers in [2, n] are prime
    int *A = malloc(sizeof(int) * (size_t)(n - 1));
    if (!A) return NULL;

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            A[count++] = i;   // pack densely, no gaps
        }
    }
    *count_out = count;
    return A;
}

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}