#include<stdio.h>
#include<stdlib.h>
// declared
struct Stack{
    int top;
    int capacity;
    int *array;
};

//initialise/create
struct Stack *createStack(int capacity){
    // create the outer structure
    struct Stack *S = malloc(sizeof(struct Stack));
    S->capacity = capacity;
    S->top = -1;
    // create the engine
    S->array = malloc(sizeof(S->array)*capacity);
}
// push
void push(struct Stack *S,int data){
    S->top += 1;
    S->array[S->top] = data;
}
// pop
void pop(struct Stack *S){
    S->top--;
}
int main()
{
    return 0;
}

