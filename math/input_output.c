#include<stdio.h>
int multiply(int a, int b);
int main() {
    int a, b, product;
    a = 14;
    b = 12;
    product = a*b;
    int over = multiply(100000, 200000); // 
    // 0100 1010 1000 0001 0111 1100 1000 0000 0000 first 32 bit with 1 which means negative do the 2 complent
    // input into a calculator with binary to get the number then add the negative sign 
    char *p = (char*) &over;

    printf("%d\n", over);
    printf("%d\n", *(p + 2));
    printf("Product of %d and %d is %d\n", a, b, product);
    scanf("%d %d", &a, &b); // Accepts multiple spaces (strips it) and all continues eof line characters.
    printf("Product of %d and %d is %d\n", a, b, multiply(a, b));
}


int multiply(int a, int b){
    return a*b;
}






