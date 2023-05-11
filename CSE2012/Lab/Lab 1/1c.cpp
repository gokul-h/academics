// Swap two numbers
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int i, temp, a, b;
    vector<int> v = {2, 1, 3, 5, 4};
    vector<int> t;
    cout << "Vector is:" << endl;
    for (auto x: v) {
        cout << x << " ";
    }
    cout << "\nEnter positions to be swapped" << endl;
    cout << "1: ";
    cin >> a;
    cout << "2:";
    cin >> b;

    //Swap
    temp = v[a];
    v[a] = v[b];
    v[b] = temp;

    cout << "New vector is:" << endl;
    for (auto x: v) {
        cout << x << " ";
    }
    return 0;
}