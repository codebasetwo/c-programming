#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <limits.h>

struct BNode;
struct BNode* get_new_node(int data);
struct BNode* insert(struct BNode* root, int data);
int search(struct BNode* root, int data);
int find_min_max(struct BNode* root, bool flag);
int find_max(struct BNode* root);
int find_min(struct BNode* root);
int find_height(struct BNode* root);
int max(int a, int b);
void level_order(struct BNode* root); 
void post_order(struct BNode* root);
void in_order(struct BNode* root);
void pre_order(struct BNode* root);
bool is_binary_search_tree(struct BNode* root, int min_value, int max_value);
bool is_bst(struct BNode* root);
bool is_subtree_lesser(struct BNode* root, int data);
bool is_subtree_greater(struct BNode* root, int data);
struct BNode* delete_node(struct BNode* root, int data);
int in_order_succesor(struct BNode* root, int data);
struct BNode* search2(struct BNode* root, int data);

int main(void)
{
    struct BNode* root = NULL;
    root = insert(root, 15); root = insert(root, 10);
    root = insert(root, 20); root = insert(root, 25);
    root = insert(root, 8);  root = insert(root, 12);
    int min = find_min(root);
    printf("Minimum value in BST: %d\n", min);
    int max = find_max(root);
    printf("Maximum value in BST: %d\n", max);
    int flag = false;
    int min_max = find_min_max(root, flag);
    printf("%s value in BST: %d\n", flag ? "Minimum" : "Maximum", min_max);
    int number;
    scanf("%d", &number);
    if(search(root, number) == 1) printf("Found\n");
    else printf("Not found\n");
    int height_of_tree = find_height(root);
    printf("Height of tree: %d\n", height_of_tree);
    level_order(root);
    pre_order(root);
    printf("\n");
    post_order(root);
    printf("\n");
    in_order(root);
    printf("\n");
    is_bst(root);
    printf("%s\n", is_bst(root) ? "Tree is a BST" : "Tree is not a BST" );
    root = delete_node(root, 10);
    in_order(root);
    printf("\n");
    int parent = 12;
    int child = in_order_succesor(root, parent);
    printf("Sucessor of parent: %d is %d\n", parent, child);
    return 0;

}

struct BNode {
    int data;
    struct BNode* left;
    struct BNode* right;
};

struct BNode* get_new_node(int data)
{
    struct BNode* tmp = (struct BNode*)malloc(sizeof(struct BNode));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

struct BNode* insert(struct BNode* root, int data)
{
    if (root == NULL) {
        root = get_new_node(data);
        return root;
    }
    if (data <= root -> data){
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int search(struct BNode* root, int data)
{
    if (root == NULL) return 0;
    if (root -> data == data) return 1;
    else if (data < root -> data) return search(root->left, data);
    else return search(root->right, data);
}

struct BNode* search2(struct BNode* root, int data)
{
    if (root == NULL) return root;
    if (root -> data == data) return root;
    else if (data < root -> data) return search2(root->left, data);
    else return search2(root->right, data);
}

int find_min_max(struct BNode* root, bool flag)
{
    if (root == NULL) return -1;
    if (flag){
        if (root->left == NULL){
            return root->data;
        }
        return find_min_max(root->left, flag);
    }else{
        if (root -> right == NULL){
            return root->data;
        }
        return find_min_max(root->right, flag);
    }
}

int find_min(struct BNode* root){
    if(root == NULL){
        printf("Error: Tree is empty\n");
        return -1;
    }
    while (root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int find_max(struct BNode* root){
    if(root == NULL){
        printf("Error: Tree is empty\n");
        return -1;
    }
    while (root->right != NULL){
        root = root->right;
    }
    return root->data;
}

int find_height(struct BNode* root)
{
    if (root == NULL) return -1; // return 0 if counting numbeer of nodes
    int left_height = find_height(root->left);
    int right_height = find_height(root->right);

    return max(left_height, right_height) + 1;
}

int max(int a, int b){
    if (a > b) return a;
    return b;
}

/*
traversal process of visiting a node exactly once
*/

// space complxity O(1) best case O(h)
//time complexity O(n) node
void level_order(struct BNode* root) {
    if (root == NULL) {
        return;
    }
    // Create a queue using a fixed-size array (assuming a tree with <= 100 nodes)
    struct BNode* queue[100];
    int front = 0;
    int rear = 0;
    // 1. Enqueue the root node
    queue[rear++] = root;
    // 2. Loop while the queue is not empty
    while (front < rear) {
        // Dequeue (get the node at the front)
        struct BNode* current = queue[front++];
        // Process the node (e.g., print its data)
        printf("%d ", current->data);
        // Enqueue left child if it exists
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        // Enqueue right child if it exists
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

void pre_order(struct BNode* root) // space complexity O(h) time O(n) node
{
    if (root == NULL) return;
    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}
void post_order(struct BNode* root){
    if (root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ", root->data);
}
void in_order(struct BNode* root){
    if (root == NULL) return;
    in_order(root->left);
    printf("%d ", root->data); 
    in_order(root->right);
}

bool is_binary_search(struct BNode* root){
    if (root == NULL) return true;
    if (
        is_subtree_lesser(root->left, root->data)
        && is_subtree_greater(root->right, root->data)
        && is_binary_search(root->left)
        && is_binary_search(root->right)
    ) return true;
    else{
        return false;
    }
}

bool is_subtree_lesser(struct BNode* root, int data){
    if (root == NULL) return true;
    if(
        root->data <= data
        && is_subtree_lesser(root->left, data)
        && is_subtree_lesser(root->right, data)
    ) return true;
    else{
        return false;
    }
}

bool is_subtree_greater(struct BNode* root, int data){
    if (root == NULL) return true;
    if(
        root-> data > data
        && is_subtree_greater(root->left, data)
        && is_subtree_greater(root->right, data)
    ) return true;
    else{
        return false;
    }
}

bool is_binary_search_tree(struct BNode* root, int min_value, int max_value){
    if (root == NULL ) return true;
    if( root -> data > min_value 
        && root->data < max_value
        && is_binary_search_tree(root->left, min_value, root->data)
        && is_binary_search_tree(root->right, root->data, max_value)) return true;
    else{
        return false;
    }
}

bool is_bst(struct BNode* root){
    return is_binary_search_tree(root, INT_MIN, INT_MAX);
}

struct BNode* delete_node(struct BNode* root, int data){
    if (root == NULL) return root;
    if (data < root->data) root->left = delete_node(root->left, data);
    else if (data > root->data) root ->right = delete_node(root->right, data);
    else{
        // Case 1: No child(ren)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: one child
        else if (root->left == NULL){
            struct BNode* tmp = root;
            root = root->right;
            free(tmp);   
        }
        else if (root->right == NULL){
            struct BNode* tmp = root;
            root = root->left;
            free(tmp);
        }
        // Case: 3
        else {
            int value = find_min(root->right); // or max in left subtree
            root->data = value;
            root->right = delete_node(root-> right, value); 
        }
    }
    return root;
}

int in_order_succesor(struct BNode* root, int data)
{
    // Search for the data
    struct BNode *cur = search2(root, data); // O(h) for search
    if (cur == NULL) return -1;
    // Case 1: BNode has right subtree find the min in the right subtree
    if (cur->right != NULL){
        struct BNode* tmp = cur->right;
        while( tmp != NULL){
            tmp = tmp->left;
        }
        return tmp->data;
    }
    // Case 2: No right subtree
    else{
        struct BNode* succesor = NULL;
        struct BNode* ancestor = root;
        while(cur != ancestor){
            if (cur->data < ancestor->data){
                succesor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return succesor->data;
    }
}