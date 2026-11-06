#include<stdio.h>

// pointer variables are stringly typed.
int main(void) {
    int a = 1025;
    int *p = &a;
    printf("Size of int is: %lu bytes\n", sizeof(int));
    printf("Address of a: %p and value of is %d\n", p, *p);
    char *p0;
    p0 = (char*)p; // type casting
    printf("Address of a: %p and value of is %d\n", p0, *p0); // *p0 = 1 byte of a = 1025 in binary = 00000000 00000000 00000100 00000001 LSB is 1 little endian system
    printf("Address of a: %p and value of is %d\n", p0 + 1, *(p0 + 1));
    void *p1;
    p1 = p; // no type casting required
    printf("Address of a: %p and value of is %d\n", p1, *(int*)p1); // type casting required to dereference void pointer
    return 0;

}