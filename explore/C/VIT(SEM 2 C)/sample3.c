#include<stdio.h>
#include<string.h>
int main()
{
    char str1[20],str2[20],str3[20];
    scanf("%s%s",str1,str2);
    int i,j,k=0,l,flag;
    for(i=0;i<strlen(str1);i++)
    {
        flag=0; // reset for every iteration
        for(j=0;j<strlen(str2);j++)
        {
            if(str1[i]==str2[j])
                flag=1;
        }
        if(flag==0)
        {
            str3[k]=str1[i];
            k++;
        }
    }
    for(i=0;i<strlen(str2);i++)
    {
        flag=0; // reset for every iteration
        for(j=0;j<strlen(str1);j++)
        {
            if(str1[j]==str2[i])
                flag=1;
        }
        if(flag==0)
        {
            for(l=0;l<strlen(str3);l++)
            {
                if(str3[l]==str2[i])
                    break;
            }
            str3[k]=str2[i];
            k++;
        }
    }
    printf("%s",str3);
    return 0;
}
