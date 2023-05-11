#include<stdio.h>
int main(){
// Input order of matrix and declare the matrix
int m,n;
// MATRIX A
// Input the number of row (m)
printf("Enter the details for matrix A");
scanf("%d",&m);
// Input the number of column(n)
scanf("%d",&n);
// Test loop to check whether elements are inputted correctly
// printf("%d%d",m,n);
int matrix_a[m][n];

//Input matrix_a
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&matrix_a[i][j]);
    }
}
// Test loop to check wether matrix is inputted correctly
for(int i=0;i<m;i++){
        printf("\n");
    for(int j=0;j<n;j++){
        printf("%d ",matrix_a[i][j]);
    }
}
// TEST LOOP ENDS HERE

// Input order of matrix and declare the matrix
int p,q;
// MATRIX A
// Input the number of row (p)
printf("Enter the details for matrix B");
scanf("%d",&p);
// Input the number of column(q)
scanf("%d",&q);
// Test loop to check whether elements are inputted correctly
// printf("%d%d",p,q);
int matrix_b[p][q];

//Input matrix_b
for(int i=0;i<p;i++){
    for(int j=0;j<q;j++){
        scanf("%d",&matrix_b[i][j]);
    }
}
// Test loop to check wether matrix is inputted correctly

for(int i=0;i<p;i++){
        printf("\n");
    for(int j=0;j<q;j++){
        printf("%d ",matrix_b[i][j]);
    }
}
//TEST LOOP ENDS HERE


return 0;
}
