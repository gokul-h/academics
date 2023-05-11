// Program for singly Linked List

#include<stdio.h>
#include<stdlib.h>  // For malloc

//Declaring Linked List
struct ListNode{
    int data;
    struct ListNode *next;
};

//Print all data in the Linked List
void printList(struct ListNode *head){
    struct ListNode *cur;   // Initialize current pointer as head
    for(cur=head;cur!=NULL;cur=cur->next){ //point to next address after each iteration
        printf("%d ",cur->data);
    }
    printf("\n");
}

// Finding Size of the list
int listSize(struct ListNode *head){
    int count=0;
    struct ListNode *cur;
    for(cur=head;cur!=NULL;cur=cur->next){
        count++;
    }
    return count;
}

//Inserting a node at the beginning
struct ListNode *insertAtBeginning(struct ListNode *head,int data){
    struct ListNode *temp;
    temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = data;  //Creating a new node
    temp->next = NULL;
    if(head==NULL){     // If the List is Empty
        head = temp;
        head->next=NULL;
    }
    else{
        temp->next = head;
        head = temp;
    }
    return head;
}

//Inserting a node at the end
struct ListNode *insertAtEnd(struct ListNode *head,int data){
    struct ListNode *temp, *cur;
    temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = NULL;
    cur = head;
    if(cur==NULL){  // If the List is Empty
        head=temp;
    }
    else{
        while(cur->next!=NULL){     // For getting the last node
            cur = cur->next;
        }
        cur->next = temp;
    }
    return head;
}

//Inserting a node at an intermediary node
struct ListNode *insertAtGivenPosition(struct ListNode *head,int data,int n){
    struct ListNode *new,*pred = head;
    new = (struct ListNode*) malloc(sizeof(struct ListNode));
    new->data = data;
    new->next = NULL;
    //inserting at head (special case)
    if(n<=1){
        new->next = head;
        return new;
    }
    n-=1;
    while(--n&&pred!=NULL){
        pred=pred->next;
    }
    if(pred==NULL){                 //?
        return NULL;
    }
    new->next = pred->next;
    pred->next = new;
    return head;
}

//Deleting a node at the beginning
void *deleteFirst(struct ListNode **head){
    struct ListNode *temp;
    temp = *head;               //copy address of node to a pointer
    *head = (*head)->next;      //change the head pointer
    free(temp);                 //Delete the node
    return NULL;
}

//Deleting a node at the end
void *deleteLast(struct ListNode **head){
    struct ListNode *temp =NULL;
    struct ListNode *current = *head;
    while(current->next){
        temp=current;
        current = current->next;
    }
    temp->next = NULL;
    free(current);
    return NULL;
}

//Deleting a node at an intermediary node
void delete(struct ListNode **head,int position){
    int k=1;
    struct ListNode *p,*q;
    if(*head==NULL){
        printf("List Empty");
        return;
    }
    p = *head;
    if(position==1){
        *head = (*head)->next;
        free(p);
        return;
    }
    else {
        while((p!=NULL)&&k<position){
            k++;
            q=p;
            p=p->next;
        }
        if(p==NULL){
            printf("Position does not exist.\n");
            return;
        }
        else{
            q->next = p->next;
            free(p);
        }
         
    }

}

// Deleting the entire list
void *deleteLinkedList(struct ListNode **head){
    struct ListNode *auxiliaryNode,*iterator;
    iterator = *head;
    while(iterator){                //Delete one node at a time from beginning
        auxiliaryNode = iterator->next;
        free(iterator);
        iterator = auxiliaryNode;
    }
    *head = NULL;
    return NULL;
}

// Main Program
int main(){
    struct ListNode *head=NULL;
    printf("\nList at the beginning\n");
    head = insertAtBeginning(head,6);
    printf("listSize:%d\n", listSize(head));
    printList(head);

    printf("\nInserting at the end\n");
    head = insertAtEnd(head,5);
    printf("listSize:%d\n", listSize(head));
    printList(head);

    printf("\nInserting at the given position\n");
    head = insertAtGivenPosition(head,8,2);
    printf("listSize:%d\n", listSize(head));
    printList(head);

    printf("\nAfter deleting first node\n");
    deleteFirst(&head);
    printf("listSize:%d\n", listSize(head));
    printList(head);

    printf("\nRestoring\n");
    head = insertAtEnd(head,6);
    printf("listSize:%d\n", listSize(head));
    printList(head);

    printf("\nDeleting particular node\n");
    delete(&head,2);
    printf("listSize:%d\n", listSize(head));
    printList(head);

    printf("\nAfter deleting last node\n");
    deleteLast(&head);
    printf("listSize:%d\n", listSize(head));
    printList(head);

    printf("\nAfter deleting whole list\n");
    deleteLinkedList(&head);
    printf("listSize:%d\n", listSize(head));
    printList(head);

    return 0;
}

