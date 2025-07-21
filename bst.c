#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node *createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


//addition in BST

struct Node *insertionInBinaryTree(int value, struct Node* root){
    if(root == NULL){
        return createNode(value);
    }
    if(root->data > value){
        root->left = insertionInBinaryTree(value, root->left);
    }else{
        root->right = insertionInBinaryTree(value, root->right);
    }
    return root;
}

int main(){
    struct Node *root = NULL;
    root = insertionInBinaryTree(30, root);
    insertionInBinaryTree(15, root);
    insertionInBinaryTree(45, root);
    insertionInBinaryTree(2, root);
    insertionInBinaryTree(6, root);
    return 0;
}