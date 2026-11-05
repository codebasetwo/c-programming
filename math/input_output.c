#include<stdio.h>
int multiply(int a, int b);
int main() {
    int a, b, product;
    a = 14;
    b = 12;
    product = a*b;
    printf("Product of %d and %d is %d\n", a, b, product);
    scanf("%d %d", &a, &b); // Accepts multiple spaces (strips it) and all continues eof line characters.
    printf("Product of %d and %d is %d\n", a, b, multiply(a, b));
}


int multiply(int a, int b){
    return a*b;
}




