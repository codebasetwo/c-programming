// Program to print calculate simple interest
#include <stdio.h>
float calculate_simple_interest(int principal, int rate, int time);
int main() {
    printf("Hello, world!\n");
    int principal; // Variable declaration
    int rate = 10; // Variable declaration and initialization
    int time = 2;
    principal = 20; // Variable initialization

    float si = calculate_simple_interest(principal, rate, time);
    printf("%.1f\n", si);
    return 0;
}


float calculate_simple_interest(int principal, int rate, int time) {
    float simple_interest = (principal * rate * time) / 100;
    return simple_interest;
}

