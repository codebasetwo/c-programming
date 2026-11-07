#include<stdio.h>
#include<stdlib.h>

// int total;
int square(int x)
{
    return x*x;
}

int square_sum(int x, int y)
{
    int z = square(x+y); // (x+y)^2
    return z;
}

int main(){
    int a = 4;
    int b = 8;
    int total = square_sum(a, b);
    printf("output = %d\n", total);

    // malloc returns void pointer so we cast
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);

    int *A = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        A[i] = i+1;
    }
    //  (int*)realloc(A, 0) // equivalent to free(A);
    // (int*)realloc(NULL, sizeof(int)) // equivalent to malloc; create a new block does not copy anything from previous block
    int* B = (int*)realloc(A, 2*n*sizeof(int)); // takes a previous pointer and reallocates the memory for a new size
    printf("Prev block address = %p, New block address %p\n", A, B);
    for (int i =0; i < 2*n; i++){
        printf("%d\n", B[i]);
    }
    // int *b = (int *)calloc(n, sizeof(int)); // calloc fills the values with 0
    // *p = 10;
    // printf("%d\n", *p);
    // free(p); double free will be detected

    // *p = 20;
    // printf("%d\n", *p);
    // free(p);

}