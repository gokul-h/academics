#include <stdio.h>
int main()
{ 
	char s[100];
	fgets(s,sizeof(s),stdin);
	printf("Hello world\n%s",s);
	return 0;
}
