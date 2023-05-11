/*
Midterm D1 - Problem 1
Let L be a linked list with two or more elements.
 Also, let L={l_1,l_2,l_3, …, l_m }  where each l_j, 1≤j≤m is an
 element of L occurring in that order in L. Let  A[1…n] be an array
 of n  integers such that, the elements of A are a subset of the
 elements of L. Write an algorithm that will check if the following
 is true and output the number of occurrences of such pairs:
 A[i],A[i+1]= l_j  l_(j+1), for some i and some j not necessarily i=j
 with 1≤i≤n, 1≤j≤m.

Example-1: L: 12->16->22->3
A: [16, 22, 12]
Output – 1
Explanation: There is only one direct link 16 -> 22
Example-2: L: 15->26->2->11->8->9
A: [26,2,15,8,9]
Output – 2
Explanation: There are two links 26->2 and 8->9

Input Format

Enter the size of L
Enter the elements of L
Enter the size of A
Enter the elements of A

Output format
Print the number of pairs.
*/

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *insert(struct Node *head,int data){
    struct Node *temp ,*cur;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    cur = head;
    if(cur==NULL){
        head = temp;
    }
    else{
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = temp;
    }
    return head;
}

int patterncounter(struct Node *head,int arr[],int size_a){
    struct Node *cur;
    int i,count=0;
    for(cur=head;cur->next!=NULL;cur=cur->next){
        for(i=0;i<(size_a-1);i++){
            if( (cur->data==arr[i]) && ((cur->next)->data==arr[i+1]) ){
                count++;
            }
        }
    }
    return count;
}

void deleteNode(struct Node *head){
    struct Node *cur=head,*temp;
    while(cur!=NULL){
        temp = cur;
        cur=cur->next;
        free(temp);
    }
    free(head);
}

int main(){
    //Input LinkedList
    int size,temp,i;
    struct Node *head=NULL;
    scanf("%d",&size);
    for(i=0;i<size;i++){
        scanf("%d",&temp);
        head = insert(head,temp);
    }

    //Input array
    int size_a;
    scanf("%d",&size_a);
    int arr[size_a];
    for(i=0;i<size_a;i++){
        scanf("%d",&arr[i]);
    }

    //Find answer
    printf("%d",patterncounter(head,arr,size_a));
    deleteNode(head);
    return 0;
}
