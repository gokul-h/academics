/*
 *Screenshot guide*
*********************************************************************
*/

#include<stdio.h>
#include<math.h>
int main(void)
{
    int k,d,count=0,index[10],rem,i;
    printf("Enter a number : ");
    scanf("%d",&k);
    printf("Enter a digit : ");
    scanf("%d",&d);
    int length = floor(log10(abs(k))) + 1;
    int k1 = k;
    for(i=1;i<length;i++)
    {
        rem = k%10;
        if(rem==d)
        {
            index[count] = length-i;
            count++;
        }
        k = k/10;
    }
    if(count)
    {
        printf("%d occurs in %d\n",d,k1);
        printf("%d occurs %d times in %d\n",d,count,k1);
        printf("%d is found in index ",d);
        for (i = 0; i < count ; ++i)
        {
            printf("%d ",index[i]);
        }
    }
    return 0;
}

/*
 *Screenshot guide*
*********************************************************************
*/