#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct linked_node;
struct linked_node* get_node(int data);
void print_linked_list(struct linked_node* root);
struct linked_node* push(struct linked_node* root, int data);
int pop(struct linked_node** root);
int is_empty(struct linked_node* root);
int top(struct linked_node* root);

int main()
{
    struct linked_node *root = NULL;
    root = push(root, 1);
    root = push(root, 2);
    root = push(root, 3);
    int poped = pop(&root);
    print_linked_list(root);
    int t = top(root);
    printf("Value at top of stack is: %d\n", t);
}

struct linked_node {
    int data;
    struct linked_node* next;
};

struct linked_node* get_node(int data){
    struct linked_node* tmp = (struct linked_node*)malloc(sizeof(struct linked_node));
    (*tmp).data = data; 
    (*tmp).next = NULL;
    return tmp;
}

void print_linked_list(struct linked_node* root){
    struct linked_node* cur = root;
    while(cur != NULL){
        printf("%d ", (*cur).data);
        cur = (*cur).next;
    }
    printf("\n");
}

struct linked_node* push(struct linked_node* root, int data){
    struct linked_node* new_node = get_node(data);
    if (root == NULL){
        return new_node;
    } 
    new_node -> next = root; 
    root = new_node;
    return root;
}

int pop(struct linked_node** root){
    if (*root == NULL) return 0;
    struct linked_node* tmp = *root;
    *root = (*root) -> next;
    free(tmp);
    return (*root) -> data;
}

int top(struct linked_node* root){
    return root -> data;
}

int is_empty(struct linked_node* root){
    if (root == NULL) return 1;
    return 0;
}

// void reverse(){
//     if (head == NULL) return;
//     // create stack of character
//     struct node* tmp = head;
//     while( tmp != NULL){
//         s.push(tmp);
//         tmp = tmp -> next
//     } 
//     tmp = s.top(); head = tmp;
//     s.pop();
//     while(!s.empty){
//         tmp -> next = s.top();
//         s.pop();
//         tmp = tmp -> next;
//     }
//     tmp -> next = NULL;
// }
