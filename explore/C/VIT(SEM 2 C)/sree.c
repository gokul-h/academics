#include<stdio.h>
#include<string.h>
int main()
{
	char a,str[20];
	int i,counter=0;
	scanf("%s",&str[20]);
	scanf("%c",&a);
	for(i=0;i<strlen(str);i++){
		if(str[i]==a){
			counter++;
		}
	}
	printf("%d",counter);
	return 0;
}
