//Print n numbers in a vector
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int i, temp;
    vector<int> v = {2, 1, 3, 5, 4};
    cout << "Numbers are:" << endl;
    for (auto x: v) {
        cout << x << endl;
    }
    return 0;
}