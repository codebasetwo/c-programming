#include<stdio.h>
int main() {
    int a = 20;
    int *p = &a;
    int **q = &p;
    int ***r = &q;
    printf("Value of a = %d\n", *p);// 20
    printf("Value of a = %p\n", *q); // address of p
    printf("Value of a = %d\n", *(*q)); // 20
    printf("Value of a = %p\n", *(*r)); // address of p
    printf("Value of a = %d\n", *(*(*r))); // 20

    ***r = 10;
    printf("Value of a = %d\n", a); // 10
    **q = *p + 2;
    printf("Value of a = %d\n", a); // 12
}

void increment(int a) {
    a = a + 1;
}