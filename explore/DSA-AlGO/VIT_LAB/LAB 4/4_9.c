/*Quetsion
Given a list split the list from the key such that the key remains in first list
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

struct Node *splitKey(struct Node *head1,struct Node *head2,int key){
    struct Node *cur=head1,*prev=head1;
    int listsize = sizeOfList(head1);
    int i,count=0;
    if(listsize%2!=0){
        listsize++;
    }
    // separate later half as sublist 2
    for(i=0;i<listsize;i++){
        cur = cur->next;
        count++;
        if(cur->data==key){
            break;
        }
    }
    head2 = cur->next;
    // Cut rest portion from head 1
    for(i=1;i<count+1;i++){
        prev = prev->next;
    }
    prev->next = NULL;
    return head2;
}

int main(void){
    struct Node *head1=NULL,*head2=NULL;
    int key;
    head1 = insertToList(head1,16);
    head1 = insertToList(head1,15);
    head1 = insertToList(head1,1);
    head1 = insertToList(head1,27);
    head1 = insertToList(head1,19);
    head1 = insertToList(head1,100);
    head1 = insertToList(head1,200);
    head1 = insertToList(head1,3);
    printf("The existing List is \n");
    printList(head1);
    printf("Enter the key:");
    scanf("%d",&key);
    head2 = splitKey(head1,head2,key);
    printf("The new SubList 1 is \n");
    printList(head1);
    printf("The new SubList 2 is \n");
    printList(head2);
    free(head1);
    free(head2);
    return 0;
}
