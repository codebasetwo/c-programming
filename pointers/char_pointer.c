#include<stdio.h>
#include<string.h>

// use const to read but cannot write
void print( char * string);
void print2(const char * string);
void print3(const char * string);

int main() {
    char C[5] = "Hello"; // char C[] = "JOHN" char C[6] = {'E', 'M', 'E', 'K', 'A', '\0'}; stores in stack
    const char *B= "hello" // stores in text section of the program compile time constant
    // B[1] = 'A';  // undefined beahviour
    int len = strlen(C);
    printf("The length of C: %d and name in C: %s\n", len, C);
    printf("Size of bytes of C: %ld\n", sizeof(C));
    char* c1;
    c1 = C; // valid c = c + 1 or c++ invalid just like array
    // c1 ++ valid 
    print(C);
    print2(C);
    print3(C);
}


void print(const char * string) {
    int i = 0;
    while (string[i] != '\0') { // *(string + i) or *string string++
        printf("%c", string[i]); // *string for printing
        i++;
    }
    printf("\n");
}

void print2(const char* string) {
    int i = 0;
    while (*(string) != '\0') { // *(string + i) or *string string++
        printf("%c", *string); // *string for printing
        string++;
    }
    printf("\n");
}

void print3(const char* string) {
    int i = 0;
    while (*(string + i) != '\0') { // *(string + i) or *string string++
        printf("%c", string[i]); // *string for printing
        i++;
    }
    printf("\n");
}