/*  5.
    Let 𝐿 = {x1, x2, … , xn} be a list of n elements. Let us search for a key K in
    the list L. If the key is presented in the list L then partition the list L into
            disjoint ordered lists L1 and L2 such that 𝐿1 = {𝑥: 𝑥 ∈ 𝐿 such that 𝑥 ≤ 𝐾}
    and 𝐿2 = {𝑦: 𝑦 ∈ 𝐿 such that 𝑦 > 𝐾}. If the key is not present in the list
            output is “empty”. Write an algorithm (using linked list) and subsequent C
            program for your algorithm to compute lists L1 and L2 for the given list L
    and key K. Note: Don’t use any inbuilt functions in your program such as
    sort.
    Example1: If L={16, 15, 1, 27, 19, 100, 200,3} and key k= 27 then
            L1={1,3,15,16,19,27} and L2={100,200}.
    Example 2: If L={16, 15, 1, 27, 19, 100, 200,3} and key k= 127 then empty.
*/

//Algorithm
//1.Divide them into two list according to the condition
//2.Sort them


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

struct Node *splitKey(struct Node *head1,struct Node *head2,int key){
    struct Node *cur=head1,*prev=head1,*temp;
    while(cur!=NULL){
        if(cur->data>key){
            head2=insertToList(head2,cur->data);
            prev->next = cur->next;
            temp = cur;
            cur=cur->next;
            free(temp);
        }
        else{
            prev = cur;
            cur=cur->next;
        }

    }
    return head2;
}

void sortList(struct Node *head){
    struct Node *cur1,*cur2;
    int temp;
    for(cur1=head;cur1!=NULL;cur1=cur1->next){
        for(cur2=cur1->next;cur2!=NULL;cur2=cur2->next){
            if(cur2->data<cur1->data){ //Swap
                temp = cur2->data;
                cur2->data = cur1->data;
                cur1->data = temp;
            }
        }
    }
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
    printf("///////Before Sorting////////\n");
    printf("The new SubList 1 is \n");
    printList(head1);
    printf("The new SubList 2 is \n");
    printList(head2);
    printf("///////After Sorting////////\n");
    sortList(head1);
    sortList(head2);
    printf("The new SubList 1 is \n");
    printList(head1);
    printf("The new SubList 2 is \n");
    if(!head2){
        printf("Is Empty!!!!");
    }
    else {
        printList(head2);
    }
    free(head1);
    free(head2);
    return 0;
}