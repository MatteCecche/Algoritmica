#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strcat1(char *s1, char *s2, int lung1, int lung2);

int main(){	

	int lung1, lung2;
	scanf("%d",&lung1);
	char s1[lung1+1];
	scanf("%s",s1);
	scanf("%d",&lung2);
	char s2[lung1+1];
	scanf("%s",s2);
	char *s4;
	s4=my_strcat1(s1,s2,lung1,lung2);
	printf("%s\n",s4);

	return 0;


}


char* my_strcat1(char *s1, char *s2, int lung1, int lung2){	

	char *s3=(char *) malloc(sizeof(char)*(lung1+lung2+1));
	int pos=0;
	int i=0;
	for(i=0;i<lung1;i++)
		s3[pos++]=s1[i];
	for(i=0;i<lung2;i++)
		s3[pos++]=s2[i];
	s3[pos]='\0';

	return s3;

	
}