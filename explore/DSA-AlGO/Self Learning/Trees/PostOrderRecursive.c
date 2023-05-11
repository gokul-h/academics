#include<stdio.h>

struct binaryTreeNode{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};

// Traverse Left---Traverse Right---Visit Node
void postOrder(struct binaryTreeNode *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d",root->data);
    }
}

int main(void){
    
    return 0;
}

