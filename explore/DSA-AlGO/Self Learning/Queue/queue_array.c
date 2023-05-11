#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Declaring a queue
struct Queue{
    int front,rear;
    int capacity;
    int size;
    int *array;
};

// Initialize queue
struct Queue *createQueue(int capacity)
{
    struct Queue *Q = malloc(sizeof(struct Queue));
    if(!Q)
        return NULL;
    Q->capacity = capacity;
    Q->front = Q->rear = -1;
    Q->size = 0;
    Q->array = malloc(Q->capacity*sizeof(int));
    if(!Q->array)
        return NULL;
    return Q;
}

int size(struct Queue *Q){
    return Q->size;
}

// Return element at the front
// Ready to be removed
int frontElement(struct Queue *Q){
    return Q->array[Q->front];
}

// Return element at the last
// Last inserted data
int rearElement(struct Queue *Q){
    return Q->array[Q->rear];
}

int isEmpty(struct Queue *Q){
    return Q->size==0;
}

int isFull(struct Queue *Q){
    return Q->size == Q->capacity;
}

// Add elements to a queue
void EnQueue(struct Queue *Q,int data) {
    if (isFull(Q))
        printf("Queue Overflow!!!");
    else {
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
}

// Remove elements from a queue
int DeQueue(struct Queue *Q){
    int data = INT_MIN;
    if(isEmpty(Q)) {
        printf("Queue is empty");
        return data;
    }
    data = Q->array[Q->front];
    // ie only one element
    if(Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
        Q->size =0;
    }
    else
    {
        // Advance front by one position
        // now EnQueue and DeQueue act as a loop
        Q->front = (Q->front+1) % Q->capacity;
        Q->size -= 1;
    }
    return data;
}

void deleteQueue(struct Queue *Q){
    if(Q){
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}

int main()
{
    int n=8,i;
    struct Queue *Q= createQueue(n);
    for(i=1;i<n;i++)
        EnQueue(Q,i);
    printf("Size of Queue: %d\n",size(Q));
    printf("Front element: %d\n", frontElement(Q));
    printf("Rear element: %d\n", rearElement(Q));
    for(i=0;i<n/2;i++)
        printf("Dequeued element is %d\n",DeQueue(Q));
    printf("Size of Queue: %d\n",size(Q));
    printf("Front element: %d\n", frontElement(Q));
    printf("Rear element: %d\n", rearElement(Q));
    deleteQueue(Q);
    return 0;

}