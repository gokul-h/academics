#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    int id;
    id=fork();
    if(id<0){
        printf("cannot create the file\n");
        exit(-1);
    }
    if(id==0){
        printf("child process\n");
        exit(0);
    }
    else{
        printf("parent process\n");
    }
    return 0;
}