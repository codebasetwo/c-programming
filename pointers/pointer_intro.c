#include<stdio.h>

int main(void) {
    int* p;
    int a;
    a = 10;
    int c = 5;
    p = &a;

    printf("The value of a is: %d\n", a);
    printf("The value of a using pointer is: %p\n", p);
    printf("The value of a using pointer is: %p\n", p + 1);
    printf("The value of a using pointer is: %d\n", *(p + 1));
    printf("The size of integer is %ld bytes\n", sizeof(int));

    printf("The value of a using pointer is: %d\n", *p);
    printf("The address of a is: %p\n", &a);
    printf("The address of a using pointer is: %p\n", &p);

    *p = 5;
    printf("The value of a after changing using pointer is: %d\n", a);
}