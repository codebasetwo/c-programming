#include<stdio.h>
int binary_search(int ints[], int value, size_t len);
int binary_search_rec(int ints[], int start, int end, int value);
int search_occurence(int ints[], int value, int len, int search_first);
int find_count(int ints[], int value, int len);
int find_rotation_count(int ints[], size_t len);
int circular_array_search(int A[], int value, int len);

int main(){
    int ints[] = { 2, 6, 13, 21, 36, 47, 63, 81, 97};
    size_t len = sizeof(ints) / sizeof(ints[0]);
    int flag = binary_search(ints, 63, len);
    int flag2 = binary_search(ints, 30, len);
    int flag3 = binary_search_rec(ints, 0, len, 81);
    int ints2[] = {2, 2, 2, 4, 5, 6, 9, 20};
    len = sizeof(ints2) / sizeof(ints2[0]);
    int count = find_count(ints2, 2, len);
    int A[] = {15, 22, 23, 28, 31, 38, 5, 6, 8, 10, 12};
    int min = find_rotation_count(A, 11);
    printf("The array is rotated %d times\n", min);
    printf("count of %d is: %d\n", 2, count);
    printf("%s\n", flag ? "Found": "Not Found");
    printf("%s\n", flag2 ? "Found": "Not Found");
    printf("%s\n", flag3 ? "Found": "Not Found");
    int x;
    printf("Enter a number :");
    scanf("%d", &x);
    int index = circular_array_search(A, x, 11);
    if (index == -1) printf("%d not found in the array", x);
    else printf("%d was found at index %d\n", x, index);

}

int binary_search(int ints[], int value, size_t len)
{
    int start = 0;
    int end = len - 1;
    while (start <= end){
        int mid = start + (end - start) / 2; // sometimes start + end may exceed max value overflow
        if (ints[mid] == value) return 1;
        else if (ints[mid] < value) start = mid + 1;
        else end =  mid - 1;
    }
    return 0;
}

int binary_search_rec(int ints[], int start, int end, int value)
{
    if (start > end) return 0;
    int mid = (start + end) / 2;
    if (ints[mid] == value) return 1;
    else if (ints[mid] < value) return binary_search_rec(ints, mid + 1, end, value);
    else return binary_search_rec(ints, start, mid-1, value);
}

int binary_search_first(int ints[], int value, int len)
{
    int low = 0;
    int high = len - 1;
    int result = -1; 
    while (low <= high){
        int mid = low + (high - low)/ 2;
        if (ints[mid] == value) {
            result = mid;
            high = mid - 1; 
        }
        else if (ints[mid] < value) low  = mid + 1;
        else high = mid - 1;
    }
    return result;
}

int search_occurence(int ints[], int value, int len, int search_first)
{
    int low = 0;
    int high = len - 1;
    int result = -1; 
    while (low <= high){
        int mid = low + (high - low)/ 2;
        if (ints[mid] == value) {
            result = mid;
            if (search_first) high = mid - 1;
            else low = mid + 1; 
        }
        else if (ints[mid] < value) low  = mid + 1;
        else high = mid - 1;
    }
    return result;
}

int find_count(int ints[], int value, int len)
{
    int first = search_occurence(ints, value, len, 1);
    int last = search_occurence(ints, value, len, 0);
    return (last - first + 1);
}

// How many times an array is sorted
// Find minimum element
int find_rotation_count(int ints[], size_t len) // min element in rotated sorted array
{
    int start = 0;
    int end = len - 1;
    while (start <= end){
        if (ints[start] <= ints[end]) return start; // Case 1: arr sorted
        int mid = start + (end - start) / 2; // sometimes start + end may exceed max value overflow
        int next = (mid + 1) % len; // if mid is the last element % will give us first element
        int prev = (mid + len - 1) % len;
        if (ints[mid] <= ints[next] && ints[mid] <= ints[prev]) return mid; // Case 2 : lowest element will have the next and prev greater than it 
        else if (ints[mid] <= ints[end]) end = mid - 1; // Case 3: mid to end is sorted
        else if (ints[mid] >= ints[start]) start = mid + 1; // Case 4 search right half
    }
    return -1;
}

int circular_array_search(int A[], int value, int len)
{
    int low = 0;
    int high = len - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (A[mid] == value) return mid;
        if (A[mid] <= A[high]){
            if (value > A[mid] && value <= A[high]) low = mid + 1;
            else high = mid - 1;
        }
        else {
            if (value >= A[low] && value < A[mid]) high = mid - 1;
            else low = mid + 1;
        }
    }
    return -1;
}