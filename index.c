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
int main(){
    struct Node* result = buildTree();
    return 0;
}

