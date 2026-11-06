#include<stdio.h>

int main() {
    int A[] = {2, 4, 5, 8, 1};
    printf("%p\n", A);
    printf("%d\n", A[2]); // prints 5
    printf("%p\n", &A[0]); // prints pointer
    printf("%d\n", *(A)); // prints 2
    printf("%d\n", *(A + 1)); // prints 4

    /*
        int *p = A valid
        A++ invalid
        p++ valid
    */
}
