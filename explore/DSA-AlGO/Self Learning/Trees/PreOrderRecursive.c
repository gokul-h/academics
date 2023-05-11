#include<stdio.h>

struct binaryTreeNode{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};

//Visit Node---Traverse Left---Traverse Right
void preOrder(struct binaryTreeNode *root){
    if(root){
        printf("%d",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main(void){

    return 0;
}


