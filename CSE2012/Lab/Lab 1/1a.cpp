//Insert n numbers in the vector
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, i, temp;
    cout << "Enter the number of elements to be inserted" << endl;
    cin >> n;
    vector<int> v;
    cout << "Enter the numbers" << endl;
    for (i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    cout << "Inputted numbers are:" << endl;
    for (i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
    return 0;
}

