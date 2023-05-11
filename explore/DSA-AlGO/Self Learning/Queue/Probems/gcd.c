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
    Q->capacity = capacity;
    Q->front = Q->rear = -1;
    Q->size = 0;
    Q->array = malloc(Q->capacity*sizeof(int));
    return Q;

}

// Add elements to a queue
void EnQueue(struct Queue *Q,int data){
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->array[Q->rear] = data;
    if(Q->front ==-1){
        Q->front = Q->rear;
    }
    Q->size += 1 ;
}

// Remove elements from a queue
int DeQueue(struct Queue *Q){
    int data = INT_MIN;
    data = Q->array[Q->front];
    if(Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
        Q->size =0;
    }
    else
    {
        Q->front = (Q->front+1) % Q->capacity;
        Q->size -= 1;
    }
    return data;
}

// Return element at the front
//Ready to be removed
int frontElement(struct Queue *Q){
    return Q->array[Q->front];
}

//gcd
int gcd(int a,int b){
    int i;
    int temp = a<b?a:b;
    int data=1;
    for(i=2;i<temp;i++)
    {
        if(a%temp==0 && b%temp==0)
        {
            data = temp;
        }
    }
    return data;
}

int main()
{
    int n,i;
    // Enter n
    scanf("%d",&n);
    struct Queue *Q;
    Q = createQueue(2);
    EnQueue(Q,0);
    EnQueue(Q,1);
    for(i=0;i<n;i++)
    {
        EnQueue(Q,(DeQueue(Q)+Front(Q)));
    }
    printf("%d",gcd(DeQueue(Q),DeQueue(Q)));
    free(Q);
    return 0;

}