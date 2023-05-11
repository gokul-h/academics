#include<iostream>
using namespace std;
inline float default(float pr)
{
    return pr=(pr*3)/100;
}
int main()
{
    float laptop=35000,charger=1500,headset=250,hdd=4000,pendrive=800;
    cout<<"Total:"<<(default(laptop)+default(chrager)+default(headset)+default(hdd)+default(pendrive))<<endl;
    return 0;
}
