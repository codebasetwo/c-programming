#include <stdio.h>

void print_factors(int n) {
    if (n <= 0) return;

    for (int i = 1; (long)i * i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);                 // small factor
            if (i != n / i)                   // avoid double-printing √n
                printf("%d ", n / i);         // mirror factor
        }
    }
    printf("\n");
}

int main(void) {
    print_factors(36);   // 1 36 2 18 3 12 4 9 6
    print_factors(28);   // 1 28 2 14 4 7
    print_factors(17);   // 1 17   (prime)
    print_factors(1);    // 1
    return 0;
}