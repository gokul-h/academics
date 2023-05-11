/*  6.
    Write an algorithm and subsequently a C program that will take as input a number k < n,
    where n is the size of the singly linked list; and interchange the
    kth and the (k+1)th element in the list.
    Your algorithm should not interchange the values directly but instead
    interchange the elements by modifying the pointer/address variables only.
    For example, if the list given is 1-2-3-4-5 and k=3, then your output should be 1-2-4-3-5.
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

struct Node *swap(struct Node *head,int k){
    struct Node *cur = head,*q,*r,*s;
    int i;
    for(i=0;i<k-2;i++){
        cur = cur->next;
    }
    q = cur->next;
    cur = cur->next;
    r = cur->next;
    s = q->next;
    q->next = r->next;
    r->next = s->next;
    printf("%d\n",q->data);
    printf("%d\n",r->data);
    free(s);
    return head;
}

int main(void){
    struct Node *head=NULL;
    int k;
    head = insertToList(head,1);
    head = insertToList(head,2);
    head = insertToList(head,3);
    head = insertToList(head,4);
    head = insertToList(head,5);
    printf("The existing List is \n");
    printList(head);
    printf("Enter the position to be swapped: ");
    scanf("%d",&k);
    head = swap(head,k);
    printf("The new List is \n");
    printList(head);
    free(head);
    return 0;
}