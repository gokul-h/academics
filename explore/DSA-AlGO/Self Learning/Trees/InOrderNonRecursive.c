#include<stdio.h>

struct binaryTreeNode{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};
struct Stack{
    int top;     // Topmost position
    int capacity;  // Size
    int *array;     // Stack
};

// Create Stack
struct Stack *createStack(int capacity){
    struct Stack *S = malloc(sizeof(struct Stack)); // Create type Stack
    if(!S) {
        return NULL;
    }
    // Initialise
    S->capacity = capacity;
    S->top = -1; // -1 indicate stack is empty
    S->array = malloc(S->capacity*sizeof(int));
    if(!S->array) {
        return NULL;
    }
    return S;
}

int isEmpty(struct Stack *S) {
    return (S->top==-1);
}

int size(struct Stack *S){
    return (S->top+1);
}

// Push (Add Element to stack)
void push(struct Stack *S,int data){
    if(isFull(S)){
        printf("Stack Overflow!");
    }
    else{
        S->array[++S->top] = data;
        // Increasing top position by 1 and placing data there
    }
}

// Pop
int pop(struct Stack *S){
    if(isEmpty(S)){
        printf("Stack Underflow!");
        return INT_MIN;
    }
    else {
        return(S->array[S->top--]);
        //Return deleted value and reduce position of top by 1
    }
}

//Delete Stack
void deleteStack(struct Stack *S){
    if(S){
        if(S->array){
            free(S->array);
        }
        free(S);
    }
}

//Traverse Left---Visit Root--Traverse Right
void inOrder(struct binaryTreeNode *root){
    struct Stack *S=createStack();
    while(1){
        while(root){
            push(S,root);
            root=root->left
        }
    }
}
int main(void){

    return 0;
}


