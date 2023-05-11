#include<stdio.h>
int main(void)
{
    //declare an array
    int array_name[10];
    //declare and initializing array with values
    int array_kunal[3] = {1,2,3};
    char ghh[5] = {'h','x','x','x','y'};

    //UserInput of an array
    int x[3][3],i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++) {
            scanf("%d", x[i][j]);
        }
    }

    return 0;
}
