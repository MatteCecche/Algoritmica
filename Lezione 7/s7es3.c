#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void *x, const void *y);
int compare1 (const void *x, const void *y);
void ordinamento(char **a, int n);


int main(){

	int n, i;
	scanf("%d",&n);
	char **a;
	a=(char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++){
		a[i]=(char *)malloc(20*sizeof(char));
		scanf("%s",a[i]);
	}	
	qsort(a,n,sizeof(char *),compare1);
	ordinamento(a,n);
	for(i=0;i<n;i++)
		printf("%s\n",a[i]);

	return 0;

}



int compare (const void *x, const void *y){

	char ** x1=(char **)x;
	char ** y1=(char **)y;
	return (strncmp(*y1,*x1,1));

}


int compare1 (const void *x, const void *y){

	char ** x1=(char **)x;
	char ** y1=(char **)y;
	int n1=strlen(*x1);
	int n2=strlen(*y1);
	return (n1-n2)*(-1);

}


void ordinamento(char **a, int n){

	int i, temp;
	int conta=0;
	for(i=0;i<n-1;i++){	
		if(strlen(a[i]) == strlen(a[i+1]))
			conta ++;
		else {
			temp=conta;
			conta=0;
			qsort(&a[i],temp,sizeof(char *),compare);
		}
	}

}






