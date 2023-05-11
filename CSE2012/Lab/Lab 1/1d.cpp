// Sort the n numbers in the vector
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

    //Sort
    sort(v.begin(), v.end());

    cout << "\nSorted vector is:" << endl;
    for (auto x: v) {
        cout << x << " ";
    }
    return 0;
}