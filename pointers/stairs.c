#include<stdio.h>

void mario(unsigned int n);
void mario2(unsigned int n);
void mario3(unsigned int n);
void mario4(unsigned int n);

int main() {
    unsigned int n;
    printf("Enter the number of stairs: ");
    scanf("%u", &n);
    mario(n);
    mario2(n);
    mario3(n);
    mario4(n);
}


void mario(unsigned int n) {
    for (int i = 0; i < n; i++){
        int spaces = n-i-1;
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        for (int k = spaces; k < n; k++) {
            printf("*");
        }
        printf("\n");
    }
}

void mario2(unsigned int n) {
    for (int i = 0; i < n; i ++) {
        int spaces = n - (n-i-1);
        for (int j = 0; j < spaces; j++) {
            printf("*");
        }
        for (int k = spaces; k < n; k++) {
            printf(" ");
        }
        printf("\n");
    }
}

void mario3(unsigned int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < n-i-1) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

void mario4(unsigned int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < n - (n-i-1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}