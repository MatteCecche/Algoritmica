#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN (1001)

char* my_strcpy(char* dest, char* src);

int main(){

	char y[MAXLEN], *x;
	int len;
	scanf("%s",y);
	len=strlen(y);
	x=(char *)malloc(sizeof(char)*(len+1));
	x=my_strcpy(x,y);
	printf("%s\n",x);

	return 0;
}

char* my_strcpy(char* dest, char* src){

	char *s =src, *d = dest;
	while((*d=*s)!='\0'){
		d++;
		s++;
	}

	return dest;
}