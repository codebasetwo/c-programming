#include<stdlib.h>
#include<stdio.h>

struct DNode* get_new_node(int data);
void print(struct DNode* head);
void insert_at_head(struct DNode** head, int data);
void print_reverse(struct DNode* head);

struct DNode{
    int data;
    struct DNode* next;
    struct DNode* prev;
};

int main()
{
    struct DNode* root = NULL;
    insert_at_head(&root, 1);
    insert_at_head(&root, 2);
    insert_at_head(&root, 3);
    insert_at_head(&root, 4);
    print(root);
    print_reverse(root);


    return 0;
}

struct DNode* get_new_node(int data)
{
    struct DNode* new_node = (struct DNode*)malloc(sizeof(struct DNode));
    new_node -> data = data;
    new_node -> next = NULL;
    new_node -> prev = NULL;
}

void insert_at_head(struct DNode** head, int data)
{
    struct DNode* tmp = get_new_node(data);
    if(*head == NULL){
        *head = tmp;
        return;
    }

    (*head) -> prev = tmp;
    tmp -> next = *head;
    *head = tmp;
}
void print(struct DNode* head){
    if (head == NULL) return;
    printf("Print Forward: ");
    struct DNode* tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp -> data);
        tmp = tmp -> next;
    }
    printf("\n");

}

void print_reverse(struct DNode* head){
    if (head == NULL) return;
    printf("Print Forward: ");
    struct DNode* tmp = head;
    while (tmp -> next != NULL) {
        tmp = tmp -> next;
    }
    printf("Print Reverse: ");
    while (tmp != NULL) {
        printf("%d ", tmp -> data);
        tmp = tmp -> prev;
    }
    printf("\n");

}