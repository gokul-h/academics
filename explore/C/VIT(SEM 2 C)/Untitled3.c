#include<stdio.h>
#include<string.h>
int main(){
char s1[25],s2[20];
scanf("%s",&s1);
scanf("%s",&s2);
int len1 = strlen(s1);
int len2 = strlen(s2);
for(int i=0;i<len1;i++)
{
    int temp = i;
    int y = len2-1;
    char c[y];
    for (int j=0;j<len2&&temp<len1;j++,temp++)
        c[j]=s1[temp];
    if (strcmp(c,s2)==0)
        printf("Substring Present\n");
}
return 0;
}
