#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    int id,a,b,c;
    printf("Enter 3 numbers\n");
    scanf("%d%d%d",&a,&b,&c);
    id=fork();

    if(id<0){
        printf("cannot perform process\n");
        exit(-1);
    }
    if(id==0){
        printf("child process-Adding three numbers\n");
        printf("%d\n",a+b+c);
        exit(0);
    }
    else{
        printf("parent process-Multiplying 3 numbers\n");
        printf("%d\n",a*b*c);
    }
    return 0;
}