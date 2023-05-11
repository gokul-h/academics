/*#include <iostream>

#include<cstring>

using namespace std;

class IceCreamCone

{

    char flavor[15];

    int no_of_scoops;

    char type_cone[15];

    int price;

    public:

    void set_data(string f="vanila",int n=1,string t="sugar")

    {

        f.copy(flavor,f.size());

        no_of_scoops=n;

        t.copy(type_cone,t.size());

    }

    void cal_price()

    {

        price=75*no_of_scoops;

        if(strcmp(type_cone,"waffle")==0)

            price=price+no_of_scoops*40;

    }

    void display()

    {

        cout<<"\nFlavor: "<<flavor<<endl;

        cout<<"Number of scoops: "<<no_of_scoops<<endl;

        cout<<"Cone Type: "<<type_cone<<endl;

        cout<<"Price: "<<price;

    }

};

int main()

{

    IceCreamCone i;

    int n,ch;

    string f,t;

    cout<<"1.To enter flavor,number of scoops and type of cone"

        <<"\n2.To enter flavor and number of  scoops"

        <<"\n3.To enter only flavor"

        <<"\n4.To use default \nEnter your choice: ";

    cin>>ch;

    switch(ch)

    {

        case 1:cout<<"Enter flavor: ";

               cin>>f;

               cout<<"Enter number of scoops: ";

               cin>>n;

               cout<<"Enter type of cone: ";

               cin>>t;

               i.set_data(f,n,t);

               break;

        case 2:cout<<"Enter flavor: ";

               cin>>f;

               cout<<"Enter number of scoops: ";

               cin>>n;

               i.set_data(f,n);

               break;

        case 3:cout<<"Enter flavor: ";

               cin>>f;

               i.set_data(f);

               break;

        default :i.set_data();

                 break;

    }

    i.cal_price();

    i.display();

    return 0;

}
*/
#include<iostream>
using namespace std;
class IceCreamCone
{
    public:
    int price,n;
    string type,fla;
    void pri(string type="Sugar",string fla="Vanilla",int n=1,int price=75)
    {
        if (type=="Wafle") price+=40;
        price=n*price;
        cout<<"\n\n\nType="<<type<<"\n"<<"Flavour="<<fla<<"\n"<<"Number="<<n<<"\n"<<"Price="<<price;
    }
};
int main()
{
    IceCreamCone ob;
    cout<<"Number=";
    cin>>ob.n;
    cout<<"\nFlavour=";
    cin>>ob.fla;
    cout<<"\nType(Sugar/Wafle)";
    cin>>ob.type;
    ob.pri(ob.type,ob.fla,ob.n);
    return 0;
}
