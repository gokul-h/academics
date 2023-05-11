// Dimensions mxn pxq
#include<iostream>

using namespace std;

#include<vector>

void read_matrix(vector<vector<int> > &mat, int a, int b) {
    cout << "Enter Matrix Elements (" << a << "x" << b << ")" << endl;
    int i, j, ele;
    for (i = 0; i < a; i++) {
        vector<int> row;
        for (j = 0; j < b; j++) {
            cin >> ele;
            row.push_back(ele);
        }
        mat.push_back(row);
    }
}

void print_matrix(vector<vector<int> > mat) {
    int n = mat.size(), i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

void matrix_multiply(vector<vector<int> > &mat1, vector<vector<int> > &mat2, vector<vector<int> > &mat3) {
    int i, j, k, n, mul = 0, add = 0;
    n = mat1.size();
    for (i = 0; i < mat1.size(); i++) {
        for (j = 0; j < mat2[0].size(); j++) {
            mat3[i][j] = 0;
            int count = 0;
            for (k = 0; k < mat1[0].size(); k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
                count++;
            }
            mul += count;
            add += count - 1;
        }
    }
    cout << "Total number of scalar multiplication = " << mul << endl;
    cout << "Total number of scalar addition = " << add << endl;
}

int main() {
    vector<vector<int> > mat1, mat2;
    int a, b, c, d;
    cout << "Enter dimensions of matrix A" << endl;
    cin >> a >> b;
    cout << "Enter dimensions of matrix B" << endl;
    cin >> c >> d;
    if (b != c) {
        cout << "Matrix not compatible!";
        exit(0);
    }
    read_matrix(mat1, a, b);
    read_matrix(mat2, c, d);
    // Create resultant matrix of size nxn and initialize all elements to 0
    vector<vector<int> > mat3(a, vector<int>(d, 0));
    matrix_multiply(mat1, mat2, mat3);
    print_matrix(mat3);
}