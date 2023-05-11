// Queue implementation using Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue{
    struct Node *front,*rear;
    int size;
};

struct Queue *createQueue(){
    struct Queue *Q;
    struct Node *temp;
    Q = malloc(sizeof(struct Queue));
    if(!Q)
        return NULL;
    temp = malloc(sizeof(struct Node));
    Q->front = NULL;
    Q->rear = NULL;
    Q->size = 0;
    return Q;
}

int frontElement(struct Queue *Q){
    return Q->front->data;
}

int rearElement(struct Queue *Q){
    return Q->rear->data;
}

int isEmpty(struct Queue *Q){
    return Q->size==0;
}

void EnQueue(struct Queue *Q,int data){
    struct Node *temp;
    temp = malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    // if List is Empty
    if(Q->rear==NULL)
        Q->front = Q->rear = temp;
    else{
        //set rear pointer as temp and also make
        //next pointer of previous node point to new rear node
        Q->rear->next = temp;
        Q->rear = temp;
    }
    Q->size++;
}

int DeQueue(struct Queue *Q){
    struct Node * temp;
    int data = INT_MIN;
    if(Q->front==NULL){
        printf("Queue is Empty!!");
    }
    else{
        temp = Q->front;
        data = temp->data;
        Q->front = Q->front->next;
        if(Q->front==NULL)
            Q->rear=NULL;
        free(temp);
    }
    Q->size--;
    return data;
}
void printQueue(struct Queue *Q){
    struct Node *temp=Q->front;
    if((Q->front==NULL) && (Q->rear==NULL)) {
        printf("Queue is Empty!\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
        if(temp!=NULL)
            printf("-> ");
    }
}

void deleteQueue(struct Queue *Q){
    struct Node *temp;
    while(Q->front){
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
    free(Q);

}

int main(){
    int i ,n=10;
    struct Queue *Q = createQueue();
    for(i=0;i<n;i++){
        EnQueue(Q,i);
    }
    printf("Element at rear: %d\n", rearElement(Q));
    printf("Element at front %d\n", frontElement(Q));
    for(i=0;i<n/2;i++){
        printf("Dequeued element is %d\n",DeQueue(Q));
    }
    printf("Element at rear: %d\n", rearElement(Q));
    printf("Element at front %d\n", frontElement(Q));
    if(isEmpty(Q))
        printf("Queue is Empty!\n");
    else
        printf("Queue is not Empty!\n");
    printQueue(Q);
    deleteQueue(Q);
    return 0;
}