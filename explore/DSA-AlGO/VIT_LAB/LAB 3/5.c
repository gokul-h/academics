/*  5.
    Using Stacks implement a queue. Try minimizing on the number
    of stacks being used.
*/
// Stack implementation using dynamic array
// doubleStack Function is added

//Stack using c
#include<stdio.h>
#include <stdlib.h>
#include<limits.h>

struct Stack{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity){
    struct Stack *S = malloc(sizeof(struct Stack));
    if(!S) {
        return NULL;
    }
    S->capacity = capacity;
    S->top = -1;
    S->array = malloc(S->capacity*sizeof(int ));
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

int isFull(struct Stack *S){
    return (S->top==S->capacity-1);
}

// Doubling the array everytime its full
void doubleStack(struct Stack *S){
    S->capacity*=2;
    S->array = realloc(S->array,S->capacity* sizeof(int));
}

void push(struct Stack *S,int data){
    if(isFull(S)){
        doubleStack(S);
    }
    S->array[++S->top] = data;

}

int pop(struct Stack *S){
    if(isEmpty(S)){
        printf("Stack Underflow!");
        return INT_MIN;
    }
    else {
        return(S->array[S->top--]);
    }
}

int peek(struct Stack *S){
    if(isEmpty(S)){
        printf("Stack is Empty!");
        return INT_MIN;
    } else{
        return (S->array[S->top]);
    }
}

void deleteStack(struct Stack *S){
    if(S){
        if(S->array){
            free(S->array);
        }
        free(S);
    }
}


int main(void)
{
    int i,capacity=5; // capacity can be user input as well
    int elements = 20;
    struct Stack *stk = createStack(capacity);
    for(i=0;i<=elements;i++) {
        push(stk,i);
        printf("%d ",i);
    }
    printf("Topmost Element is %d\n",peek(stk));
    printf("Size of the stack is %d\n",size(stk));
    for(i=0;size(stk)!=0;i++){
        printf("Popped element is %d\n",pop(stk));
    }
    if(isEmpty(stk)){
        printf("Stack is Empty");
    }
    else {
        printf("Stack is not empty");
    }
    deleteStack(stk);
    return 0;
}