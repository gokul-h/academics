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

    // Delete element from beginning
    v.erase(v.begin());

    // Delete element from last
    v.pop_back();

    cout << "\nNew vector is:" << endl;
    for (auto x: v) {
        cout << x << " ";
    }
    return 0;
}