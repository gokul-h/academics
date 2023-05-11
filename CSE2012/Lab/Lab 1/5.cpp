// Menu Driven Program for implementation of queue
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
    for (i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    cout << "Max element is: " << *max_element(v.begin(), v.end()) << endl;
    cout << "Min element is: " << *min_element(v.begin(), v.end()) << endl;
    cout << "Sum of elements is :" << accumulate(v.begin(), v.end(), 0) << endl;
    cout << "Vector after swapping:" << endl;
    for (i = 0; i < (n % 2 == 0 ? n : n - 1); i += 2) {
        temp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = temp;
    }
    for (i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}
