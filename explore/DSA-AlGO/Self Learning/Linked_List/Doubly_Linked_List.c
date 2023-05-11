// DOubly linked list
#include<stdio.h>
#include<stdlib.h>
struct DNode{
    int data;
    struct DNode *next;
    struct DNode *prev;
};
//Inserting and removing New Node at
//1.Beginning
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
//2.End
//3.At a given position

//printing the list
void printList(struct DNode *head){
    struct DNode *cur;
    for(cur=head;cur!=NULL;cur=cur->next){
        printf("%d",cur->data);
    }
    printf("\n");
}

int main(){
    struct DNode *head=NULL;
    insertBeginning(&head,1);
    insertBeginning(&head,2);
    insertBeginning(&head,3);
    insertBeginning(&head,4);
    insertBeginning(&head,5);
    printf("The list is\n");
    printList(head);
    return 0;
}