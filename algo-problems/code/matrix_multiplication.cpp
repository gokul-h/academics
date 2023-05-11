#include<bits/stdc++.h>

using namespace std;

void inputMatrix(vector<vector<double>> & arr, int n) {
    cout<<"Enter "<<n*n<<" elements of "<<n<<"x"<<n<<" matrix"<<endl;
    int temp;
    for(int i=0;i<n;i++){
        vector<double> row;
        for(int j=0;j<n;j++){
            cin>>temp;
            row.push_back(temp);
        }
        arr.push_back(row);
    }
}
void initializeMatrix(vector<vector<double>> & arr, int n) {
    for(int i=0;i<n;i++){
        vector<double> row;
        for(int j=0;j<n;j++){
            row.push_back(0);
        }
        arr.push_back(row);
    }
}

void matrixMultiplication(vector<vector<double>> & arr1,vector<vector<double>> & arr2,vector<vector<double>> & arr3,int n) {
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr3[i][j] = 0;
            for(k=0;k<n;k++){
                arr3[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }
}

void printMatrix(vector<vector<double>> & arr, int n) {
    cout<<"Elements of "<<n<<"x"<<n<<" matrix are"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<double>> a, b,c;
    int n;
    cout<<"Enter the dimension of square matrix"<<endl;
    cin>>n;
    inputMatrix(a, n);
    inputMatrix(b, n);
    initializeMatrix(c, n);
    matrixMultiplication(a, b, c, n);
    printMatrix(c,n);
    return 0;
}
