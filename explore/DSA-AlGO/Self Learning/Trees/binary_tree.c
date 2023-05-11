//Basic Binary Tree
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
//Create a New Node
struct node *newNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right=NULL;
    return temp;
}

void insertElement(struct node *root,int data){
    struct Queue *Q;
    you
}
int main(void){
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    return 0;
}
