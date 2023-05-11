// ROOTs of an Quadratic Equation
// Quadratic Equation is of the form ax^2 + Bx + c
// Input:= a,b,c
// x = (b*b - 4*a*c)^0.5
// Processing := (-b + x)/2*a = (-b - x)/2*a
// Output := answer

#include<stdio.h>
// Function declaration
int find_root_exist(int a,int b,int c);
int find_root(int a,int b, int c,int x);
// To find whether root exist or not
int find_root_exist(int a,int b,int c)
{
    int x;
    x = (b*b - 4*a*c);
    if (x>0)
    {
        find_root(a,b,c,x);
        //Two Distinct real roots
    }
    else if (x==0)
    {
        find_root(a,b,c,x);
        //Equal roots
    }
    else if (x<0)
    {
        printf("Roots are imaginary");
        //No roots imaginary roots

    }
}
//4.1234
//4.12345678
int find_root(int a,int b, int c,int x)
{
    float root1,root2;
    root1=(-b + (x)^(1/2))/2*a ;
    root2= (-b - (x)^(1/2))/2*a;
    printf("Root1:%f\n",root1);
    printf("Root2:%f\n",root2);
}
int main()
{
    int a,b,c;
    printf("Program to find the roots of a quadratic equation\n");
    printf("Please enter values a b and c in a*x^2 + b*x + c\n");
    scanf("%d%d%d",&a,&b,&c);
    find_root_exist(a,b,c);
    return 0;
}