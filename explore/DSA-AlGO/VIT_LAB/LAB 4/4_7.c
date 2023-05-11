/*  7.
    Given two linked lists 𝐿1 and 𝐿2, write a C program to output and store the
    elements of 𝐿1 ∩ 𝐿2 into a third list 𝐿3.
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

void printList(struct Node *head){
    struct Node *cur;
    for(cur=head;cur!=NULL;cur=cur->next){
        printf("%d ",cur->data);
    }
    printf("\n");
}

struct Node *listUnion(struct Node *head1,struct Node *head2,struct Node *head3){
    struct Node *cur1,*cur2;
    for(cur1=head1;cur1!=NULL;cur1=cur1->next){
        for(cur2=head2->next;cur2!=NULL;cur2=cur2->next){
            if(cur1->data==cur2->data){
                head3 = insertToList(head3,cur1->data);
            }
        }
    }
    return head3;
}

int main(void){
    struct Node *head1=NULL,*head2=NULL,*head3=NULL;
    head1 = insertToList(head1,1);
    head1 = insertToList(head1,2);
    head1 = insertToList(head1,3);
    head1 = insertToList(head1,4);
    head1 = insertToList(head1,5);
    head2 = insertToList(head2,6);
    head2 = insertToList(head2,2);
    head2 = insertToList(head2,3);
    head2 = insertToList(head2,7);
    head2 = insertToList(head2,8);
    printf(" List 1 is \n");
    printList(head1);
    printf(" List 2 is \n");
    printList(head2);
    head3 = listUnion(head1,head2,head3);
    printf("The common List is \n");
    printList(head3);
    free(head1);
    free(head2);
    free(head3);
    return 0;
}