#include<stdio.h>
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int kunal[m][n];
    for(int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&kunal[i][j]);
        }
    }

    for(int i=0;i<m;i++){
            printf("\n");
        for (int j=0;j<n;j++){
            printf("%d ",kunal[i][j]);
        }
    }
    printf("\n");
    for(int i = 0; i < m ; i++){
        for (int j=0;j<n;j++){
            // whatever conditin is given use it here
            if (i==j){
                    if (kunal[i][j]>5){
                            printf("%d ",kunal[i][j]);
                    }
            }
        }
    }



    return 0;
}
