#include<stdio.h>
#include<string.h>
int main(){
char s1[25],s2[25];
scanf("%s",&s1);
scanf("%s",&s2);
int len = strlen(s1);
if (len%2==0){
   int x = len/2;
   for(int i =0;i<x;i++){
    printf("%c",s1[i]);
   }
   for(int i =0;i<strlen(s2);i++){
    printf("%c",s2[i]);
   }
   for(int i =x;i<len;i++){
    printf("%c",s1[i]);
   }
}

return 0;}
