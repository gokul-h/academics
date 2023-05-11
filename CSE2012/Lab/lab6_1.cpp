#include<bits/stdc++.h>

using namespace std;

void read_matrix(vector<vector<int> > &mat, int a) {
    cout << "Enter Matrix Elements (" << a << "x" << a << ")" << endl;
    int i, j, ele;
    for (i = 0; i < a; i++) {
        vector<int> row;
        for (j = 0; j < a; j++) {
            cin >> ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }
}

void strassen_multiplication(vector<vector<int> > &a, vector<vector<int> > &b, vector<vector<int> > &c, int n) {
    int a11, a12, a22, a21, b11, b12, b21, b22;
    int p, q, r, s, t, u, v;

    a11 = (a[1][1] * a[1][2]) + (a[1][2] * a[2][1]);
    a12 = (a[1][3] * a[2][4]) + (a[1][4] * a[2][3]);
    a21 = (a[3][1] * a[4][2]) + (a[3][2] * a[4][1]);
    a22 = (a[2][3] * a[1][4]) + (a[2][4] * a[1][3]);
    b11 = (b[1][1] * b[1][2]) + (b[1][2] * b[2][1]);
    b12 = (b[1][3] * b[2][4]) + (b[1][4] * b[2][3]);
    b21 = (b[3][1] * b[4][2]) + (b[3][2] * b[4][1]);
    b22 = (b[2][3] * b[1][4]) + (b[2][4] * b[1][3]);

    //assigning variables acc. to strassen's algo
    p = (a11 + a22) * (b11 + b22);
    q = (a21 + a22) * b11;
    r = a11 * (b12 - b22);
    s = a22 * (b21 - b11);
    t = (a11 + a12) * b22;
    u = (a11 - a21) * (b11 + b12);
    v = (a12 - a22) * (b21 + b22);

    c[0][0] = t + s - q + u;
    c[0][1] = p + q;
    c[1][0] = r + s;
    c[1][1] = p + t - r - v;

}

void print_matrix(vector<vector<int> > mat) {
    int n = (int) mat.size(), i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> a, b, c;
    int n = 2; // change matrix size here
    read_matrix(a, n);
    read_matrix(b, n);
    strassen_multiplication(a, b, c, n);
    print_matrix(c);
}