#include <stdio.h>
#define N 1000000

int confronto(int a[], int b[], int c, int d);

int main(){

	int x, y, i;
	scanf("%d",&x);
	int a[N];
	for(i=0;i<x;i++)
		scanf("%d",&a[i]);
	scanf("%d",&y);
	int b[N];
	for(i=0;i<y;i++)
		scanf("%d",&b[i]);
	printf("%d\n",confronto(a,b,x,y));

	return 0;

}

int confronto(int a[], int b[], int c, int d){

	int i=0;
	int j=0;
	int conta=0;
	while(i<c && j<d){
		if(a[i]>b[j]) j++;
		if(a[i]<b[j]) i++;
		if(a[i]==b[j]){
			conta++;
			i++;
			j++;
		}
	}

	return conta;

}