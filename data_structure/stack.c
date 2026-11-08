#include<stdlib.h>
#include<stdio.h>
// LIFO
#define MAX_SIZE 101
int STACK[MAX_SIZE];
int top = -1;

void push(int x);
int pop();
int is_empty();
int top_of_stack();

int main(){
    push(1);
    push(2);
    push(3);
    int value = pop();
    printf("Value just popped from stack is: %d\n", value);
    int t = top_of_stack(); 
    printf("Element at top of stack is: %d\n", t);
    int empty = is_empty(); printf("%d\n", empty);
}

void push(int x){
    if (top == MAX_SIZE - 1) {
        printf("Error: stack overflow\n");
        return;
    }
    STACK[++top] = x;
}
int pop(){
    if (top != -1){
        printf("Error: No element to pop\n");
        return 0;
    }
    int value = STACK[top]; 
    top -= 1;
    return value; 
}
int is_empty(){
    if (top == -1) return 1;
    return 0; 
}
int top_of_stack(){
    return STACK[top];
}
/*
check_parenthesis()
solution scan from left to right
if opening symbol add it to the stack
if closing symbol remove last opening symbol from the list 
{

}

*/
