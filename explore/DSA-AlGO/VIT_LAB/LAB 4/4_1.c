/*
    Use Singly Linked lists for all the programs given.
    When finished with all the questions w.r.t Singly linked Lists,
    write subsequent C programs to answer all the questions using Doubly Linked Lists.
    4_1-4_8 SLL
    4_11-4_18 DLL
    4_21-4_28 CLL
*/

/*  1.
    Write a C Program to count the number of elements in a given linked list.

    Algorithm:
    1.Declare basic Linked list and operations
    2.Insert values to the Linked list
    3.define a function where a for loop is used to count number of elements
    4.A pointer maybe initialised to the value of head and then incremented in for loop
 */
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// Insert Node at any position
struct Node *insert(struct Node *head,int data){
    struct Node *temp, *cur;
    temp = (struct Node*)malloc(sizeof(struct Node));
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

// calculate size
int size(struct Node *head){
    struct Node *cur;
    int count=0;
    for(cur=head;cur!=NULL;cur=cur->next){
        count++;
    }
    return count;
}

int main(void){
    struct Node *head=NULL;
    head = insert(head,1);
    head = insert(head,2);
    head = insert(head,3);
    head = insert(head,4);
    head = insert(head,5);
    printf("Size of Linked list is: %d", size(head));
    return 0;
}