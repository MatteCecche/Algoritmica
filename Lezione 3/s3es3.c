#include <stdio.h>
#define N 1000000

int sott(int a[], int dim);

int main(){

	int a[N];
	int x, i;
	scanf("%d",&x);
	for(i=0;i<x;i++)
		scanf("%d",&a[i]);
	printf("%d\n",sott(a,x));

	return 0;
}


int sott(int a[], int dim){

	int max=0; 
	int somma=0;
	int i;
	for(i=0;i<dim;i++){
		if(somma>0) somma+=a[i];
		else somma=a[i];
		if(somma>max) max=somma;
	}

	return max;

}