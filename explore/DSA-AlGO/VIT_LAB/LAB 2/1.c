/*
 * Question based on the code given in Question (Refer PDF in same folder)
 */

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
        //printf("hi");
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
void deleteStack(struct Stack *S){
    if(S){
        if(S->array){
            free(S->array);
        }
        free(S);
    }
}
void sort(struct Stack *stack) {
    struct Stack *temp1 = createStack(10);
    struct Stack *temp2 = createStack(10);
    int var1, var2,count=0;
    while(!isEmpty(stack)) {
        var1 = pop(stack);
        //printf("%d-var1 is %d\n",count,var1);
        if (isEmpty(temp1)) {
            push(temp1, var1);
        }
        do {
            var2 = pop(temp1);
            push(temp2, var2);
        } while ((var1 > var2) && (!isEmpty(temp1)));
        printf("Temp 2 after %dth iteration\n",count);
        while (!isEmpty(temp2)) {
            //push(stack, pop(temp1));
            printf("%d\n",pop(temp2));
        }
        while (!isEmpty(temp2)) {
            push(temp1, pop(temp2));
        }
//        printf("Temp 1 after %dth iteration\n",count);
//        while (!isEmpty(temp1)) {
//            //push(stack, pop(temp1));
//            printf("%d\n",pop(temp1));
//        }
        count++;
    }
    while (!isEmpty(temp1)) {
        //push(stack, pop(temp1));
        printf("%d\n",pop(temp1));
    }
    deleteStack(temp1);
    deleteStack(temp2);
}

int main(void){
    struct Stack *stack1 = createStack(10);
    push(stack1, 7);
    push(stack1, 5);
    push(stack1, 3);
    push(stack1, 8);
    push(stack1, 2);
    // Stack is 7 5 3 8 2
    sort(stack1);
    //while(!isEmpty(stack1)){
       // printf("%d\n",pop(stack1));
    //}
    deleteStack(stack1);
    return 0;
}
