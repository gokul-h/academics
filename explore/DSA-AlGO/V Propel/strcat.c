#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
struct Queue{
    int front,rear,capacity,size;
    char *array;
};

struct Queue *createQueue(int capacity) {
    struct Queue *Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->capacity = capacity;
    Q->front = Q->rear = -1;
    Q->size=0;
    Q->array = (char*)malloc(Q->capacity*sizeof(int));
    return Q;
}

void EnQueue(struct Queue *Q,char data){
    Q->rear = (Q->rear +1) % Q->capacity;
    Q->array[Q->rear]= data;
    if(Q->front == -1){
        Q->front = Q->rear;
    }
    Q->size +=1;
}

int DeQueue(struct Queue *Q){
    char data = CHAR_MIN;
    data = Q->array[Q->front];
    if(Q->front == Q->rear){
        Q->front = Q->rear=-1;
        Q->size=0;
    }
    else{
        Q->front = (Q->front+1) % Q->capacity;
        Q->size-=1;
    }
    return data;

}

int main(){
    char num[5];
    scanf("%s",num);
    int n,k,i,j;
    char rans,ans;
    scanf("%d%d",&n,&k);
    struct Queue *Q;
    Q= createQueue((n+1)*strlen(num));
    for(j=0;j<n+1;j++){
        for(i=0;i<strlen(num);i++){
            EnQueue(Q,num[i]);
        }
    }
    for(i=0;i<(n+1)*strlen(num);i++){
        ans = DeQueue(Q);
        printf("%c",ans);
        if(i==k-1){
            rans=ans;
        }
    }
    printf("\n%c",rans);
    free(Q);
    return 0;
}