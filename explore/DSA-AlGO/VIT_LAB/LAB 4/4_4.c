/*  4.
    Given a list, split it into two sublist  one for the front half,
    and one for the back half. If the number of elements is odd, the extra element should go in the front list.
    For example, the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}.
*/
/*
Algorithm
1.Declare and define linked list and required operations
2.Input a list
3.create a new head
4.point the new head to middle element
5.make next pointer of the predecessor element point to NULL
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *insertToList(struct Node *head,int data){
    struct Node *new,*cur=head;
    new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    if(cur==NULL){
        head = new;
    }
    else{
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = new;
    }
    return head;
}

int sizeOfList(struct Node *head){
    struct Node *cur;
    int count=0;
    for(cur=head;cur!=NULL;cur=cur->next){
        count++;
    }
    return count;
}

void printList(struct Node *head){
    struct Node *cur;
    for(cur=head;cur!=NULL;cur=cur->next){
        printf("%d ",cur->data);
    }
    printf("\n");
}

struct Node *split(struct Node *head1,struct Node *head2){
    struct Node *cur=head1,*prev=head1;
    int listsize = sizeOfList(head1);
    int i;
    if(listsize%2!=0){
        listsize++;
    }
    // separate later half as sublist 2
    for(i=0;i<listsize/2;i++){
        cur = cur->next;
    }
    head2 = cur;
    // Cut rest portion from head 1
    for(i=1;i<listsize/2;i++){
        prev = prev->next;
    }
    prev->next = NULL;
    return head2;
}

int main(void){
    struct Node *head1=NULL,*head2=NULL;
    head1 = insertToList(head1,1);
    head1 = insertToList(head1,2);
    head1 = insertToList(head1,3);
    head1 = insertToList(head1,4);
    head1 = insertToList(head1,5);
    printf("The existing List is \n");
    printList(head1);
    head2 = split(head1,head2);
    printf("The new SubList 1 is \n");
    printList(head1);
    printf("The new SubList 2 is \n");
    printList(head2);
    free(head1);
    free(head2);
    return 0;
}