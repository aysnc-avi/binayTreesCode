#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree recursively from user input
struct Node* buildTree() {
    int val;
    printf("Enter value (-1 for no node): ");
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* root = createNode(val);

    printf("Enter left child of %d\n", val);
    root->left = buildTree();

    printf("Enter right child of %d\n", val);
    root->right = buildTree();

    return root;
}
void preOrderTraversal(struct Node *root){
    if(root == NULL){
        return;
    } 
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(struct Node *root){
    if(root == NULL){
        return;
    } 
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}
void InOrderTraversal(struct Node *root){
    if(root == NULL){
        return;
    } 
    InOrderTraversal(root->left);
    printf("%d ", root->data);
    InOrderTraversal(root->right);
}



int main(){
    struct Node* result = buildTree();
    printf("Preorder traversal: \n");
    preOrderTraversal(result);
    return 0;
}

