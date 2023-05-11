#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<map>
using namespace std;

int convert(int sec,int min,int hr)
{
    return sec*10000+min*100+hr;
}

vector<string>split(string &s,char delim)
{
    stringstream ss (s);
    string item;
    vector<string>elems;
    while(getline(ss,item,delim))
    {
        elems.push_back(item);

    }
    return elems;
}

int time(string s)
{
    vector<string>v=split(s,':');
    return(stoi(v[0]),stoi(v[1]));
}

int main()
{
    string fname;
    cin>>fname;
    ifstream f;
    f.open(fname);
    string s;
    map<string,pair<int,int>>mp;
    while(!f.eof())
    {
        getline(f,s);
        vector<string>v=split(s,'#');

        for(int i=0;i<v.size();i+=3)
        {
            mp[v[i]]=make_pair((time(v[i+1])),(time(v[i+2])));

        }
    }
    f.close();

    int n;
    cin>>n;
    string name;
    int hh,mm,ss;
    for(int i=0;i<n;i++)
    {
        cin>>name>>hh>>mm>>ss;
        // int t=(ss,mm,hh);
        int d =convert(ss,mm,hh);
        auto st=mp[name];
        if((d)>st.first&&(d)<st.second)
        {
            cout<<"Not logged in\n";
        }
        else
        {
            cout<<"Logged in\n";
        }
    }
    return 0;
}