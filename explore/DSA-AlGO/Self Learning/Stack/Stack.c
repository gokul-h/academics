// Stack implementation using static array

//Stack using c
#include<stdio.h>
#include<stdlib.h> // For malloc()
#include<limits.h> // for INT_MIN

// Define Structure stack (Custom Data Type)
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

int isFull(struct Stack *S){
    return (S->top==S->capacity-1);
    // check if top position is equal to maximum capacity
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

// Return last inserted/Topmost element
int peek(struct Stack *S){
    if(isEmpty(S)){
        printf("Stack is Empty!");
        return INT_MIN;
    } else{
        return (S->array[S->top]);
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

int main(void)
{
    int i,capacity=7; // capacity can be user input as well
    struct Stack *stk = createStack(capacity);
    // here *stk is just a pointer which can hold address of  a structure
    // we use malloc in create stack to create real memory for stack

    // Add elements
    for(i=0;i<capacity;i++) {
        push(stk,i);
    }

    // Print last inserted/topmost element
    printf("Topmost Element is %d\n",peek(stk));

    // Print size of the stack
    printf("Size of the stack is %d\n",size(stk));

    // pop elements / delete
    // deleting all elements
    for(i=0;i<capacity;i++){
        printf("Popped element is %d\n",pop(stk));
    }

    if(isEmpty(stk)){
        printf("Stack is Empty");
    }
    else {
        printf("Stack is not empty");
    }

    // deleting stack
    deleteStack(stk);
    return 0;
}