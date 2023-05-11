#include <bits/stdc++.h>
using namespace std;
// Function to sort the array
void insertionSort(vector<int> &vec) {
    for (auto it = vec.begin(); it != vec.end(); it++) {
        // Searching the upper bound, i.e., first
        // element greater than *it from beginning
        auto const insertion_point =
                upper_bound(vec.begin(), it, *it);

        // Shifting the unsorted part
        rotate(insertion_point, it, it + 1);
    }
}
void swap_arr(vector<int> &vec,int n) {
    int temp;
    for(int i=0;i<n-1;i+=2){
        temp = vec[i];
        vec[i] = vec[i+1];
        vec[i+1] = temp;
    }
}
// Function to print the array
void print(vector<int> vec) {
    for (int x: vec)
        cout << x << " ";
    cout << '\n';
}

// Driver code
int main() {
    int n,i,temp;
    n=7;
    vector<int> arr;
    for (i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    insertionSort(arr);
    swap_arr(arr,n);
    print(arr);
}


