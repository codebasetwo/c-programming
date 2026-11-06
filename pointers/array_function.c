#include<stdio.h>
#include<stdlib.h>

int sum_of_elements(int A[], int size);
void double_value(int* A, int size);
int main() {
    int A[] = {1, 2, 3, 4,5};
    int size = sizeof(A) / sizeof(A[0]);
    int total = sum_of_elements(A, size);
    printf("Sum of element in array A: %d\n", total);

    double_value(A, size);
    for  (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int sum_of_elements(int A[], int size) {
    int i, sum = 0;
    // int size = sizeof(A) / sizeof(A[0]); // using this here results in undefined behavior
    // this is because int A[] is actually int* in function argument so it takes the address of first element
    for (i = 0; i < size; i++ ){
        sum += A[i];
    }
    return sum;
}

void double_value(int* A, int size) {
    for (int i = 0; i < size; i++) {
        A[i] = 2 * A[i];
    }
}