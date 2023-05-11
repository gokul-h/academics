// Menu Driven Program for implementation of queue
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    list<int> l;
    int n, i, temp;
    cout << "Enter the number of elements to be inserted" << endl;
    cin >> n;
    cout << "Enter the numbers" << endl;
    for (i = 0; i < n; i++) {
        cin >> temp;
        l.push_back(temp);
    }
    cout << "List is:" << endl;
    for (auto x: l) {
        cout << x << endl;
    }
    // Sort List
    cout << "Sorted list" << endl;
    l.sort();
    for (auto x: l) {
        cout << x << endl;
    }
    // Reverse sorted list

    cout << "Reverse sorted list" << endl;
    l.reverse();
    for (auto x: l) {
        cout << x << endl;
    }
    return 0;
}
