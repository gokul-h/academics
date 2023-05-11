#include<iostream>
using namespace std;
inline int police(float h,int a,float c)
{
    int temp=0;
    if( (h>5.2 && h<5.6) && (a>18 && a<25) && (c>45) )
    {
        temp=1;
    }
    return temp;
}
int main()
{
    float h,c;
    int a;
    cout<<"Enter height(inch) age and chest(cm) measurements\n";
    cin>>h>>a>>c;
    if(police(h,a,c)) cout<<"Selected";
    else cout<<"Rejected";
    return 0;
}


