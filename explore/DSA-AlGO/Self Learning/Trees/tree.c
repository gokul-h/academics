#include<stdio.h>

struct binaryTreeNode{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};


int main(void){
    int variable1;  //Original Variable
    variable1=9;
    int *variable1_adress;
    variable1_adress = &variable1;// Address to variable
    printf("%d\n",variable1);
    printf("%p\n",variable1_adress);
    printf("%d",*variable1_adress);
    return 0;
}



