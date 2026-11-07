#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// when reference to a fucntion is passed to another 
// function then that function is called a call back function

int compare(int a, int b)
{
    // change to change the ranking mechanism
    if (a > b) return -1;
    return 1;
}

int absolute_compare(int a, int b){
    if (abs(a)> abs(b)) return  1;
    return -1;
}

void bubble_sort(int A[], int n, int (*compare)(int, int)){
    int i, j, tmp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i; j < n; j++) {
            if (compare(A[i], A[j]) > 0) { // descending if > if a > b return 1
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}

void bubble_sort2(int A[], int n){
    int i, j, tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (A[j] < A[j+1]) {
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }

}


int add(int a , int b)
{
    return a + b;
}

void print_hello()
{
    printf("Hello\n");
}

int qsort_compare(const void *a, const void* b)
{
    int A = *((int*)a); // typecasting into int* to and get value
    int B = *((int*)b);
    return A-B;
}

// int* p(int , int); // declaring a function that returns a pinter to integer
int main() {
    int c;
    // Pointer to function that should take (int, int)
    // as argument/parameter and return int
    int (*p) (int , int); // declaring a function pointer
    p = &add;// or add
    c = (*p)(2, 3); // de-referncing and executing the function p(2, 3)
    printf("%d\n", c);

    void (*h)();
    h = print_hello;
    h();
    int A[] = {3, 2, 1, 5, 6, 0, 4, -1}; 
    int B[] = {-31, 22, -1, 50, -6, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);
    // int (*compare)(int, int) = compare;
    // bubble_sort2(A, n);
    bubble_sort(A, n, compare);
    for (int i = 0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    bubble_sort(B, m, absolute_compare);
    for (int i = 0; i<m; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    int C[] = {-31, 22, -1, 50, -6, 4};
    // 
    qsort(C, m, sizeof(int), qsort_compare);
    for (int i = 0; i<m; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");
}