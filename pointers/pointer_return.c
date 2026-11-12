#include<stdio.h>
#include<stdlib.h>
void print_hello()
{
    printf("Hell World!");
}

int* add(int *a, int *b)
{
    int c = (*a) + (*b); // use malloc instead for heap memory
    // not okay to return address of local variable
    return &c; // returning this is bad because it may no longer be available in stack
}

int* add2(int *a, int *b)
{
    int *c = (int*)malloc(sizeof(int));
    *c = (*a) + (*b); // use malloc instead for heap memory
    return c; // okay beacuse it leaves in the heap
}


int main(void)
{
    // it is ok to pass a local variable from bottom to top in the call stack
    int a = 5, b = 6;
    // not ok to return address of local variable from top to bottom in the stack
    // int* ptr = add(&a, &b); // call by reference
    int* ptr2 = add2(&a, &b);
    print_hello(); 
    printf("Sum = %d\n", *ptr2);
}