
#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int data;
    struct ListNode *next;
};


void printList(struct ListNode *head){
    struct ListNode *cur;
    for(cur=head;cur!=NULL;cur=cur->next){
        printf("%d ",cur->data);
    }
    printf("\n");
}

struct ListNode *insertAtBeginning(struct ListNode *head,int data){
    struct ListNode *temp;
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = NULL;
    if(head==NULL){
        head = temp;
        head->next=NULL;
    }
    else{
        temp->next = head;
        head = temp;
    }
    return head;
}


void *deleteLinkedList(struct ListNode **head){
    struct ListNode *auxiliaryNode,*iterator;
    iterator = *head;
    while(iterator){
        auxiliaryNode = iterator->next;
        free(iterator);
        iterator = auxiliaryNode;
    }
    *head = NULL;
    return NULL;
}
struct DNode{
    int data;
    struct DNode *next;
    struct DNode *prev;
};

void insertBeginning(struct DNode **head,int data){
    struct DNode *cur=*head;
    struct DNode *new = (struct DNode*)malloc(sizeof(struct DNode));
    if(!new){
        printf("Memory Error");
    }
    new->prev = NULL;
    new->data = data;
    new->next=NULL;
    if(cur==NULL){
        *head = new;

    }else {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
}
int deleteFirst(struct DNode **head){
    struct DNode *temp;
    temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    (*head)->prev =NULL;
    free(temp);
    return data;
}

int deleteLast(struct DNode **head){
    struct DNode *temp =NULL;
    struct DNode *current = *head;
    while(current->next){
        temp=current;
        current = current->next;
    }
    int data = temp->data;
    temp->next = NULL;
    free(current);
    return data;
}
void logic(struct ListNode *head,struct DNode *dhead){
    int temp;
    while(dhead!=NULL){
        temp = deleteFirst(&dhead);
        insertAtBeginning(head,temp);
        temp = deleteLast(&dhead);
        insertAtBeginning(head,temp);
        dhead = dhead->next;
    }
}

int main(){
    struct ListNode *head=NULL;
    struct DNode *Dhead = NULL;
    //Insert element into DLL
    int n,i,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        insertBeginning(&Dhead,temp);
    }
    //Process
    logic(head,Dhead);
    //Print
    printList(head);
    deleteLinkedList(&head);
    return 0;
}

