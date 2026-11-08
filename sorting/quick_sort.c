#include<stdio.h>

int quick_sort(int A[], int start, int end);
int partition(int A[], int start, int end);
void swap(int *a , int *b);

int main(){
    int A[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int start = 0;
    int end = sizeof(A) / sizeof(A[0]);

    quick_sort(A, start, end- 1);
    for (int i = 0; i < end; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}


int quick_sort(int A[], int start, int end) {
    if (start < end) {
        int p_index = partition(A, start, end);
        quick_sort(A, start, p_index - 1);
        quick_sort(A, p_index + 1, end);
    }
}

int partition(int A[], int start, int end){
    int pivot = A[end];
    int p_index = start;
    for (int i = start; i < end; i++){
        if (A[i] <= pivot) {
            // swap
            swap(A + i, A + p_index);
            p_index++;
        }
    }
    swap(&A[p_index], &A[end]);
    return p_index;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}