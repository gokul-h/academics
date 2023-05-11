/*  2.
    Let Q be a queue data structure and it has n numbers. Write C
    code to implement the following functions on Q
    a. Write a function to compute the maximum number in Q.
    b. Write a function to compute the sum of the even numbers in
    Q.
    c. Write a function to replace all odd numbers with -1 in Q.
*/
// Queue implementation using size doubling
// added resize function
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Declaring a queue
struct Queue {
    int front, rear;
    int capacity;
    int size;
    int *array;
};

// Initialize queue
struct Queue *createQueue(int capacity) {
    struct Queue *Q = malloc(sizeof(struct Queue));
    if (!Q)
        return NULL;
    Q->capacity = capacity;
    Q->front = Q->rear = -1;
    Q->size = 0;
    Q->array = malloc(Q->capacity * sizeof(int));
    if (!Q->array)
        return NULL;
    return Q;

}

int size(struct Queue *Q) {
    return Q->size;
}

// Return element at the front
// Ready to be removed
int frontElement(struct Queue *Q) {
    return Q->array[Q->front];
}

// Return element at the last
// Last inserted data
int rearElement(struct Queue *Q) {
    return Q->array[Q->rear];
}

int isEmpty(struct Queue *Q) {
    return Q->size == 0;
}

int isFull(struct Queue *Q) {
    return Q->size == Q->capacity;
}

void resize(struct Queue *Q) {
    int size = Q->capacity;
    Q->capacity *= 2;
    Q->array = realloc(Q->array, sizeof(int) * Q->capacity);
    if (!Q->array) {
        printf("Memory Error");
        return;
    }
    if (Q->front > Q->rear) {
        for (int i = 0; i < Q->front; i++) {
            Q->array[i + size] = Q->array[i];
        }
        Q->rear += size;
    }
}

// Add elements to a queue
void EnQueue(struct Queue *Q, int data) {
    if (isFull(Q))
        resize(Q);
    Q->rear = (Q->rear + 1) % Q->capacity;
    // Since this is a circular array index must not exceed capacity
    // Modulus operator helps us lock in that
    Q->array[Q->rear] = data;
    // If it is empty
    if (Q->front == -1) {
        Q->front = Q->rear;
    }
    Q->size += 1;
}

// Remove elements from a queue
int DeQueue(struct Queue *Q) {
    int data = INT_MIN;
    if (isEmpty(Q)) {
        printf("Queue is empty");
        return data;
    }
    data = Q->array[Q->front];
    // ie only one element
    if (Q->front == Q->rear) {
        Q->front = Q->rear = -1;
        Q->size = 0;
    } else {
        // Advance front by one position
        // now EnQueue and DeQueue act as a loop
        Q->front = (Q->front + 1) % Q->capacity;
        Q->size -= 1;
    }
    return data;
}

void deleteQueue(struct Queue *Q) {
    if (Q) {
        if (Q->array)
            free(Q->array);
        free(Q);
    }
}

void maxQueue(struct Queue *Q) {
    int i, temp, max = DeQueue(Q);
    EnQueue(Q, max);
    for (i = 0; i < Q->size - 1; i++) {
        temp = DeQueue(Q);
        if (temp > max) {
            max = temp;
        }
        EnQueue(Q, temp);
    }
    printf("\nMax Element is %d", max);
}

void evenSum(struct Queue *Q) {
    int i, temp, sum = 0;
    for (i = 0; i < Q->size; i++) {
        temp = DeQueue(Q);
        if (temp % 2 == 0) {
            sum += temp;
        }
        EnQueue(Q, temp);
    }
    printf("\nSum of even elements is %d", sum);
}

void replace(struct Queue *Q) {
    int i, temp,size = Q->size;
    for (i = 0; i < size; i++) {
        temp = DeQueue(Q);
        if (temp % 2 != 0) {
            EnQueue(Q, -1);
        } else {
            EnQueue(Q, temp);
        }
    }
    printf("\nReplaced Queue\n");
    for (i = 0; i < size; i++) {
        printf("%d ", DeQueue(Q));
    }
}


int main() {
    int n = 8, i;
    struct Queue *Q = createQueue(n);
    printf("Queue is \n");
    for (i = 1; i < n; i++) {
        EnQueue(Q, i);
        printf("%d ", i);
    }
    maxQueue(Q);
    evenSum(Q);
    replace(Q);
    deleteQueue(Q);
    return 0;

}

