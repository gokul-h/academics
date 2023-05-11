// Merge Sort using STL
// Dictionary Order
#include<iostream>
using namespace std;
int main(){
    cout<<"Hello World";
    vector<string> str ={"clock","point","dozen","paper","fling","solve","title","shift","green","solid",};

    return 0;
}
// Menu Driven Program for implementation of queue
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    // Insert the elements Eg: 202 323 707 932 965 463 763 461
    int n, i, temp;
    cout << "Enter the number of elements to be inserted" << endl;
    cin >> n;
    vector<int> v;
    cout << "Enter the numbers" << endl;
    for (i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    // Print the vector
    cout << "Inputted numbers are:" << endl;
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout<<endl;
    //Merge Sort


    // Print sorted vector
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}
