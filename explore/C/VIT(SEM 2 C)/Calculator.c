
#include<stdio.h>
int addition(int a,int b);
int sub(int a,int b);
int mul(int a,int b);
int div(int a,int b);
int modulo(int a,int b);
int main()
{
    int a,b,oper;
    printf("Enter the two numbers\n");
    scanf("%d%d",&a,&b);
    printf("Enter the operation to be done\n");
    printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Modulo\n");
    scanf("%d",&oper);
    switch(oper)
    {
        case 1:
            printf("Answer is: %d",add(a,b));
            break;
        case 2:
            printf("Answer is: %d",sub(a,b));
            break;
        case 3:
             printf("Answer is: %d",mul(a,b));
            break;
        case 4:
             printf("Answer is: %d",div(a,b));
            break;
        case 5:
             printf("Answer is: %d",modulo(a,b));
            break;
        default:
            printf("Wrong choice");
    }
    return 0;
}
int add(int a,int b)
{
    return a+b;
}

int sub(int a,int b)
{
     return a-b;
}
int mul(int a,int b)
{
    return a*b;
}
int div(int a,int b)
{
    return a/b;
}
int modulo(int a,int b)
{
    return a%b;
}
