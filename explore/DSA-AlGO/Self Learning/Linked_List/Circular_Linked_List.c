// Program for singly Linked List

#include<stdio.h>
#include<stdlib.h>  // For malloc

//Declaring Linked List
struct CNode{
    int data;
    struct CNode *next;
};

//Print all data in the Linked List
void printList(struct CNode *head){
    struct CNode *cur=head; // Initialize current pointer as head
    if(head==NULL)
        return;
    do{
        printf("%d ",cur->data);
        cur = cur->next;
    }while(cur!=head);
    printf("\n");
}

// Finding Size of the list
int listSize(struct CNode *head){
    int count=0;
    struct CNode *cur=head;
    if (head==NULL)
        return 0;
    //Stop counting once it reaches head again
    do{
        cur = cur->next;
        count++;
    }while(cur!=head);
    return count;
}

//Inserting a node at the beginning
struct CNode *insertAtBeginning(struct CNode *head,int data){
    struct CNode *temp;
    temp = (struct CNode *)malloc(sizeof(struct CNode));
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
struct CNode *insertAtEnd(struct CNode *head,int data){
    struct CNode *temp, *cur;
    temp = (struct CNode*)malloc(sizeof(struct CNode));
    if(!temp){
        printf("Memory error!");
        return NULL;
    }
    temp->data = data;
    temp->next = head;
    cur = head;
    if(cur==NULL){  // If the List is Empty
        head=temp;
    }
    else{
        do{
            cur = cur->next;
        }while(cur!=head);
        cur->next = temp;
    }
    return head;
}

//Inserting a node at an intermediary node
struct CNode *insertAtGivenPosition(struct CNode *head,int data,int n){
    struct CNode *new,*pred = head;
    new = (struct CNode*) malloc(sizeof(struct CNode));
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
void *deleteFirst(struct CNode **head){
    struct CNode *temp;
    temp = *head;               //copy address of node to a pointer
    *head = (*head)->next;      //change the head pointer
    free(temp);                 //Delete the node
    return NULL;
}

//Deleting a node at the end
void *deleteLast(struct CNode **head){
    struct CNode *temp =NULL;
    struct CNode *current = *head;
    while(current->next){
        temp=current;
        current = current->next;
    }
    temp->next = NULL;
    free(current);
    return NULL;
}

//Deleting a node at an intermediary node
void delete(struct CNode **head,int position){
    int k=1;
    struct CNode *p,*q;
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
void *deleteLinkedList(struct CNode **head){
    struct CNode *auxiliaryNode,*iterator;
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
    struct CNode *head=NULL;
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

