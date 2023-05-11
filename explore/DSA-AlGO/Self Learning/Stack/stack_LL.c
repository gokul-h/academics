//Stack implementation using LL

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node *next;
};

struct Stack{
    int size;
    struct Node *top;
};

struct Stack *createStack(){
    struct Stack *S = malloc(sizeof(struct Stack));
    S->top = NULL;
    S->size = 0;
    return S;
}

int isEmpty(struct Stack *S){
    return S->top==NULL;
}

void push(struct Stack *S,int data){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = S->top;
    S->top = temp;
    S->size++;
}

int pop(struct Stack *S){
    int data;
    struct Node *temp;
    if(isEmpty(S)){
        return INT_MIN;
    }
    temp = S->top;
    S->top = S->top->next;
    data = temp->data;
    free(temp);
    S->size--;
    return data;
}

int peek(struct Stack *S){
    if(isEmpty(S))
        return INT_MIN;
    return S->top->data;
}

void deleteStack(struct Stack *S){
    struct Node *temp,*p;
    p = S->top;
    while(p){
        temp = p->next;
        p = p->next;
        free(temp);
    }
    free(S);
}

int main(){
    int i,capacity = 10;
    struct Stack *S = createStack();
    for(i=0;i<=capacity;i++) {
        push(S,i);
    }
    printf("Topmost element is %d\n", peek(S));
    printf("Stack size is %d\n",S->size);
    for(i=0;i<=capacity;i++) {
        printf("Popped element is %d\n",pop(S));
    }
    if(isEmpty(S)){
        printf("Stack is empty");
    }
    deleteStack(S);
    return 0;
}
