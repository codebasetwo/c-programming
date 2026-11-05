#include<stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void sieve(int n);

int main(void) {
    sieve(50);
}

void sieve(int n) {
    bool *primes = malloc(sizeof(bool) * (size_t)(n + 1));
    for (int i = 0; i <= n; i++) {
        primes[i] = 1;
    }
    primes[0] = 0;
    primes[1] = 0;

    for (int i = 2; i * i <=n; i++) {
        if (primes[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = 0;
            }
        }
    }
    for (int i = 0; i <= n; i++)
        if (primes[i])
            printf("%d ", i);
    printf("\n");
    free(primes);
}