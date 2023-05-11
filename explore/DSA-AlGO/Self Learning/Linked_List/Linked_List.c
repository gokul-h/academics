// Linked List
#include<stdio.h>
#include<stdlib.h>
//Declare Linked List
struct ListNode {
    int data;       // Datum
    struct ListNode *next; //Pointer to next node
};

//Print LL
void print(struct ListNode *head){
    struct ListNode *cur = head;
    for(cur=head;cur!=NULL;cur=cur->next){
        printf("%d",cur->data);
    }
    printf("\n");
}

//calculating size of linked list
int size(struct ListNode *head){
    struct ListNode *cur =head;
    int count=0;
    for(cur=head;cur!=NULL;cur=cur->next){
        count++;
    }
    return count;
}
//Insert a new node at the beginning
struct ListNode *insertAtBeginning(struct ListNode *head,int data){
    struct ListNode *temp;
    temp=(struct ListNode *)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = NULL;
    // If list is empty
    if(head==NULL){
        head=temp;
        head->next=NULL;
    }
    //If list is not empty
    else {
        temp->next = head;
        head=temp;
    }
    return head;
}

//Insert a new node at the end
struct ListNode *insertAtEnd(struct ListNode **head,int data){
    struct ListNode *temp,*cur;
    temp = (struct ListNode *) malloc(sizeof(struct ListNode));
    *cur = *head;
    temp->data = data;
    temp->next = NULL;
    //Empty List
    if(cur==NULL){
        head=temp;
    } else {
        //Find the current end and then add
        while(cur->next!=NULL){
            cur=cur->next;
        }
        //Now cur is the last node
        cur->next = temp;
    }
    return head;
};

// Deleting the first node in lin ked list
void *DeleteFirstNode(struct ListNode **head){
    struct ListNode *temp;
    if(*head==NULL){
        printf("Cant delete since list is empty");
    temp = *head;
    *head=(*head)->next;
    free(temp);
}
//Deleting the last node
























int main(){

    return 0;
}
