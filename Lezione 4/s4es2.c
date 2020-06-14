#include <stdio.h>
#define N 1000000

void Insertion_Sort(int a[], int x);

int main(){

	int x, i;
	scanf("%d",&x);
	int a[N];
	for(i=0;i<x;i++)
		scanf("%d",&a[i]);
	Insertion_Sort(a,x);

	return 0;

}


void Insertion_Sort(int a[], int x){

	int j, key, i;
	for(i=1;i<x;i++){
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	for(i=0;i<x;i++)
		printf("%d\n",a[i]);

}