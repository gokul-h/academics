#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stack {
    int top;
    int capacity;
    int *array;
};

struct stack *createStack(int capacity) {
    struct stack *S = malloc(sizeof(struct stack));
    if (!S) {
        return NULL;
    }
    S->capacity = capacity;
    S->top = -1;
    S->array = malloc(sizeof(int) * S->capacity);
    if (!S->array) {
        return NULL;
    }
    return S;
}

int isEmpty(struct stack *S) {
    return S->top == -1;
}

int size(struct stack *S) {
    return (S->top + 1);
}

int isFull(struct stack *S) {
    return S->top == S->capacity - 1;
}

void push(struct stack *S, int data) {
    if (isFull(S)) {
        printf("Stack Overflow");
    } else {
        S->array[++S->top] = data;
    }
}

int pop(struct stack *S) {
    if (isEmpty(S)) {
        printf("Stack Underflow");
        return INT_MIN;
    } else {
        return (S->array[S->top--]);
    }
}

void deleteElement(struct stack *S, int m) {
    int i;
    struct stack *S1 = createStack(10);
    for (i = 0; i <m-1; i++) {
        push(S1, pop(S));
    }
    pop(S);
    for (i = 0; i <m-1; i++) {
        push(S, pop(S1));
    }
}

void printStack(struct stack *S) {
    while (!isEmpty(S)) {
        printf("%d ", pop(S));
    }
}

void deleteStack(struct stack *S) {
    if (S) {
        if (S->array) {
            free(S->array);
        }
        free(S);
    }
}

int main(void) {
    int i, m;
    //Getting a sample stack
    struct stack *S = createStack(10);
    for (i = 0; i < 10; i++) {
        push(S, i);
    }
    printf("Stack:\n");
    for (i = 9; i >= 0; i--) {
        printf("%d ",i);
    }
    printf("\nEnter the position whose element has to be deleted\n");
    scanf("%d", &m);
    deleteElement(S, m);
    printStack(S);
    deleteStack(S);
    return 0;
}
