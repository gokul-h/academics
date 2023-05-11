#include<iostream>
using namespace std;
class UD_time
{
    int hour,min,sec;

public:
    void get();
    UD_time add(int);
    void print();
};

void UD_time::get() {
    cin>>hour>>min>>sec;
}

void UD_time::print(){
    cout<<hour<<"\t"<<min<<"\t"<<sec<<endl;
}

UD_time UD_time::add(int m) {
    UD_time t2;
    int hr;
    t2.sec= sec;
    t2.min=min+m;
    t2.hour=hour;
    if(t2.min>=60)
    {
        hr=t2.min/60;
        t2.min =t2.min-hr*60;
        t2.hour += hr;
    }
    return t2;
}

int main(){
    UD_time t1,t2;
    int min;
    t1.get();
    cin>>min;
    t2=t1.add(min);
    t2.print();
    return 0;
}