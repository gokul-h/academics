/*Pascals triangle
    Use case:
      1:-
Input = no of levels/rows
Output = Pascals Triangle
 */

void pascals_triangle(int n) {
    int arr[100];
    for (int i = 0; i < 100 ; i++){
        arr[i] = 1;
    }
    int pos = 1;
    for (int i = 1; i < n; i++) { // for levels
        for (int j = pos+1; j < pos + i ; j++) {
            for()
        }
        pos += (i + 1);
    }
}

#include<iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the no of levels/rows for pascals triangle" << endl;
    cin >> n;
    pascals_triangle(n);
    return 0;
}

