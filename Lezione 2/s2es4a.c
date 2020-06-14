#include <stdio.h>
#include <string.h>

int anagramma(unsigned char *s1, unsigned char *s2);

int main(){

	char *s1[256];
	char *s2[256];
	scanf("%s",s1);
	scanf("%s",s2);
	printf("%d\n",anagramma(s1,s2));

	return 0;

}


int anagramma(unsigned char *s1, unsigned char *s2){

	int len1=strlen(s1);
	int len2=strlen(s2);
	if(len1!=len2) return 0;
	else return 1;

}