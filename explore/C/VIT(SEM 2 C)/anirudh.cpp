#include<iostream>
using namespace std;
class area
{
    public:
        int length;
        int breadth;
        // constrcutor
        // l*b l**b l*365*b
        void area(int l,int b)
        {
            length = l;
            breadth = b;
        }

};

int main(void)
{
    int l,b;
    cin>>l>>b;
    area a1(l,b);
    //a1.setDim(l,b);
    //cout<<a1.getArea();
    return 0;
}
