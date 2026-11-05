#include<stdio.h>
void prime_factorization(int n);

int main(void) {
    prime_factorization(50);   // 2 2 3 3
    printf("\n");

}

void prime_factorization(int n) {
    if (n <= 1) {
        printf("No prime factors for %d\n", n);
        return;
    }
    int count = 0;
    while (n % 2 == 0 ) {
        n /= 2;
        count++;
    }
    printf("Count of 2: %d\n", count);

    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            printf("Count of %d: %d", i, count);
        }
    }
    // if (n != 1)
    if (n > 2) {
        printf("%d ", n);
    }
}
