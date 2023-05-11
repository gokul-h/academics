/*  2.
    Given a linked list L, write a C program to insert a node at the kth position.
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// size of the list
int size(struct Node *head){
    struct Node *temp;
    int count=0;
    for(temp=head;temp!=NULL;temp=temp->next){
        count++;
    }
    return count;
}

// Insert Node at any position
struct Node *insert(struct Node *head,int data,int k){
    struct Node *prev=head,*new;
    new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    int length = size(head);
    if(k<=1){
        new->next = head;
        return new;
    }
    else if (k<=length) {   // any value between 1 and length of list
        --k;
        while (--k && prev != NULL) {
            prev = prev->next;
        }
        if (prev->next == NULL) {
            return NULL;
        }
        new->next = prev->next;
        prev->next = new;
        return head;
    }
    else{   // any value greater than size
        while(prev->next!=NULL){
            prev = prev->next;
        }
        prev->next = new;
        return head;
    }
}

// print the list
void printList(struct Node *head){
    struct Node *cur;
    for(cur = head;cur!=NULL;cur=cur->next){
        printf("%d ",cur->data);
    }
    printf("\n");
}



int main(void){
    struct Node *head=NULL;
    int data,k;
    head = insert(head,1,1);
    head = insert(head,1,1);
    head = insert(head,1,1);
    head = insert(head,1,1);
    head = insert(head,1,1);
    printf("The existing List is \n");
    printList(head);
    printf("Enter the element to be inserted: ");
    scanf("%d",&data);
    printf("Enter the position to be inserted: ");
    scanf("%d",&k);
    head = insert(head,data,k);
    printf("The new List is \n");
    printList(head);
    return 0;
}