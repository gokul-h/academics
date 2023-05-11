#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    //Compare two string
    if(strcmp(s1,s2)==0)
    {
        cout<<"Both string are the same";
    }
    else
    {
        cout<<"Both string are different";
    }
    // Combine wo string
    strcat(s1,s2);
    cout<<s1;
    return 0;
}
