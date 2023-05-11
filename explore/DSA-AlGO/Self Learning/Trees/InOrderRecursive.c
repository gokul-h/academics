#include<stdio.h>

struct binaryTreeNode{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};

//Traverse Left---Visit Root--Traverse Right
void inOrder(struct binaryTreeNode *root){
    if(root){
        inOrder(root->left);
        printf("%d",root->data);
        inOrder(root->right);
    }
}
int main(void){

    return 0;
}


