# include<stdio.h>
#include<string.h>
int main()
{
    char str[20];
    scanf("%s",&str);
    int i,j,flag=0;
    for(i=0;i<strlen(str);i++)
    {
        for(j=0;j<strlen(str);j++)
        {
          if(i==j)
                continue;
          if (str[i]==str[j])
            flag=1;
        }
    }
    if(flag==0)
        printf("Isogram");
    else
        printf("not isogram");
    return 0;
}
