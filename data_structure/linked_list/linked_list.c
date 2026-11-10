#include<stdlib.h>
#include<stdio.h>

struct linked_node;
struct linked_node* get_node(int data);
void print_linked_list(struct linked_node* root);
struct linked_node* insert_at_end(struct linked_node* root, int data);
struct linked_node* insert(struct linked_node* root, int data);
struct linked_node* insert_recursive(struct linked_node* root, int data);
struct linked_node* insert_at_nth(struct linked_node* root, int data, size_t position);
void delete_at_nth(struct linked_node** root, int position);
void reverse(struct linked_node **root);
void print_list_reverse(struct linked_node* root);
struct linked_node* reverse_list_recursive(struct linked_node* root);

int main() {
    struct linked_node* root = NULL;
    root = insert_at_end(root, 1);
    root = insert_at_end(root, 2);
    root = insert(root, 0);
    root = insert_recursive(root, 4);
    root = insert_at_nth(root, 3, 4);
    print_linked_list(root);
    delete_at_nth(&root, 1);
    print_list_reverse(root);
    printf("\n");
    reverse(&root);
    print_linked_list(root);
    root = reverse_list_recursive(root);
    print_linked_list(root);
    return 0;
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

struct linked_node* insert_at_end(struct linked_node* root, int data){
   struct linked_node* new_node = get_node(data);
    if (root == NULL){
        return new_node;
    }
    struct linked_node* cur = root; 
    while ((*cur).next != NULL){
        cur =(*cur).next;
    }
    (*cur).next = new_node;
   return root;
}

void print_linked_list(struct linked_node* root){
    struct linked_node* cur = root;
    while(cur != NULL){
        printf("%d ", (*cur).data);
        cur = (*cur).next;
    }
    printf("\n");
}

struct linked_node* insert(struct linked_node* root, int data){
    struct linked_node* new_node = get_node(data);
    if (root == NULL){
        return new_node;
    } 
    new_node -> next = root; 
    root = new_node;
    return root;
}

struct linked_node* insert_recursive(struct linked_node* root, int data){
    if (root == NULL) {
        return get_node(data);
    }

    root -> next = insert_recursive(root-> next, data);
    return root;
}

struct linked_node* insert_at_nth(struct linked_node* root, int data, size_t position){
    struct linked_node* new_node = get_node(data);
    if (position == 1) {
        new_node -> next = root;
        root = new_node;
        return root;
    }
    struct linked_node* tmp = root;
    for(int i = 0; i < position- 2; i++){
        tmp = tmp -> next;
    }
    new_node -> next = tmp -> next;
    tmp -> next = new_node;
    return root;
}

void delete_at_nth(struct linked_node** root, int pos)
{
    struct linked_node* tmp = *root;
    if (pos == 1){
        *root = tmp -> next;
        free(tmp);
        return;
    }
    for (int i = 0; i < pos-2; i++){
        tmp = tmp -> next;
    }
    struct linked_node* tmp1 = tmp -> next;
    tmp -> next = tmp1 -> next;
    free(tmp);
}

void reverse(struct linked_node **root)
{
    struct linked_node* prev, *next, *cur;
    cur = *root;
    prev = NULL;
    while(cur != NULL){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    *root = prev;
}

void print_list_reverse(struct linked_node* root)
{
    if (root == NULL) return;
    // printf("%d ", root -> data); // print in order
    print_list_reverse(root -> next);
    printf("%d ", root -> data);
}

struct linked_node* reverse_list_recursive(struct linked_node* root) {
    // Base case: if the list is empty or has only one node, it's already reversed
    if (root == NULL || root->next == NULL) {
        return root;
    }

    // Recursively reverse the rest of the list starting from the second node
    struct linked_node* new_root = reverse_list_recursive(root->next);

    // Reverse the link between the current node and its successor
    root->next->next = root;
    root->next = NULL;

    // Return the new head of the reversed list
    return new_root;
}