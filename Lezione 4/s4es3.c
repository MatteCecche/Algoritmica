#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int Insertion_Sort(char **a[], int x);

int main(){

	int i, x;
	scanf("%d",&x);
	char **a;
	a=(char **)malloc(x*sizeof(char *));
	for(i=0;i<x;i++){
		a[i]=(char *)malloc(101*sizeof(char));
		scanf("%s",a[i]);
	}
	Insertion_Sort(a,x);

	return 0;

}


int Insertion_Sort(char **a[], int x){

	int j, i;
	char *key;
	for(i=1;i<x;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && (strcmp(a[j],key)>0)){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	for(i=0;i<x;i++)
		printf("%s\n",a[i]);
}