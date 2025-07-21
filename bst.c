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