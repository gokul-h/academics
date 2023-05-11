#include<stdio.h>
#include<stdlib.h>
void main(){
    // Create the file
    FILE *ptr;
    ptr = fopen("newfile.txt","w");
    if(ptr==NULL){
        printf("File cannot be created!");
        exit(1);
    }
    else{
        printf("File is created\n");
    }
    fclose(ptr);

    //Write to file
    ptr = fopen("newfile.txt","w");
    if(ptr==NULL) exit(1);
    char text[20];
    printf("Enter the text to be saved in file\n");
    scanf("%s",text);
    fputs(text,ptr);
    fclose(ptr);

    // Read from File
    ptr = fopen("newfile.txt","r");
    if(ptr==NULL) exit(1);
    char str[20];
    printf("Reading from file...\n");
    if(fgets(str,20,ptr)!=NULL) puts(str);
    fclose(ptr);
}