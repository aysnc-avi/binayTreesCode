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

// In order predecessor for deletion in binary

struct Node *inOrderPredecessor(struct Node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}
// Deletion in Binary 

struct Node *deletionInBinaryTree(struct Node* root, int value){

    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(root->data > value){
        root->left = deletionInBinaryTree(root->left, value);
    }else if(root->data < value){
        root->right = deletionInBinaryTree(root->right, value);
    } else {
        struct Node *iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deletionInBinaryTree(root->left, iPre->data);
    }
    return root;
}

struct Node *searchInBinaryTree(int value, struct Node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->data == value){
        return root;
    }
    if(root->data > value){
        return searchInBinaryTree(value, root->left);
    }else{
        return searchInBinaryTree(value, root->right);
    }
}
int main(){
    struct Node *root = NULL;
    root = insertionInBinaryTree(30, root);
    insertionInBinaryTree(15, root);
    insertionInBinaryTree(45, root);
    insertionInBinaryTree(2, root);
    insertionInBinaryTree(6, root);
    struct Node *search = searchInBinaryTree(45, root);
    printf("%d", search->data);
    return 0;
}