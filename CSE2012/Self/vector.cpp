#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> sample;
    for(int i=0;i<5;i++) sample.push_back(i);
    for(auto i=sample.begin();i!=sample.end();i++)
        cout<<*i;
    cout<<endl<<sample.max_size();
    cout << "\nReference operator [g] : sample[2] = " << sample[2];

    cout << "\nat : sample.at(4) = " << sample.at(4);

    cout << "\nfront() : sample.front() = " << sample.front();

    cout << "\nback() : sample.back() = " << sample.back();
    return 0;
}

