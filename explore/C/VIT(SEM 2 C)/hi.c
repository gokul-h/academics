#include<stdio.h>
#include<string.h>
int main(){
    // Input the matrix of order n
    int n,test=1;
    scanf("%d",&n);

    // Input the matrix
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=test;
            test++;
        }
    }
    // Test loop to print inputted matrix
    /*
    for(int i=0;i<n;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);

        }
    }
    */
    printf("\n\n\n");
    // MAIN CODE BLOCK
    int hello[(n-1)*(n-1)][2][2],counter=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            hello[counter][0][0]=matrix[i][j];
            hello[counter][0][1]=0;
            hello[counter][1][0]=matrix[i+1][j];
            hello[counter][1][1]=matrix[i+1][j+1];

            //TEST PRINT
            /*
            printf("1-%d-\n",matrix[i][j]);
            printf("2-0\n");
            printf("3-%d-\n",matrix[i+1][j]);
            printf("4-%d-\n",matrix[i+1][j+1]);
                printf("\n\n\n");
            printf("1c-%d-\n",hello[counter][0][0]);
            printf("2c-%d\n",hello[counter][0][1]);
            printf("3c-%d-\n",hello[counter][1][0]);
            printf("4c-%d-\n",hello[counter][1][1]);
                printf("\n\n\n");
            */
                counter++;

        }
    }
    // Loop to compute the sum of all such small matrix
    int temp = (n-1)*(n-1);
    int sum[temp];
    for(int i=0;i<temp;i++){
            sum[i]=0;
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                sum[i] += hello[i][j][k];
            }
        }
    }
    //Loop to find the maximum in sum
    int max = sum[0],temp_i;
    for(int i=0;i<temp;i++){
        if (sum[i]>max){
            max = sum[i];
            temp_i = i;
        }
    }
    printf("%d",max);
    for(int j=0;j<2;j++){
        printf("\n");
            for(int k=0;k<2;k++){
                    printf("%d ",hello[temp_i][j][k]);
            }
    }
return 0;
}
