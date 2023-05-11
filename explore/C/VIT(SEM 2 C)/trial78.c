
#include <stdio.h>
int add(int n1,int n2);
int sub(int n1 , int n2);
int multyply(int n1,int n2);
int divide(int n1,int n2);
int modulo(int n1 ,int n2);
void main()
{​​​​
    int a,b,c,d,e,f,g;
    printf("enter two number\n");
    scanf("%d",&a);
    scanf("%d",&b);
    c=add(a,b);
    d=sub(a,b);
    e=multyply(a,b);
    f=divide(a,b);
    g=modulo(a,b);
    printf("addition of 2 number %d",c);
    printf("subtraction of 2 number %d",d);
    printf("multipication of 2 number %d",e);
    printf("division of 2 number %d",f);
    printf("modulo of 2 number %d",g);
}​​​​
int add(int n1,int n2)
{​​​​
    int a1;
    a1=n1+n2;
    return a1;
    }​​​​
int sub(int n1, int n2)
{​​​​
    int b1;
    b1=n1-n2;
    return b1
}​​​​

int multyply(int n1,int n2)
{​​​​
    int c1;
    c1=n1*n2;
    return c1;
}​​​​
int divide(int n1, int n2)
{​​​​
    int d1;
    d1=n1/n2;
    return d1;
}​​​​
int modulo(int n1,int n2)
{​​​​
    int e1;
    e1=n1%n2;
    return e1;
}​​​​

