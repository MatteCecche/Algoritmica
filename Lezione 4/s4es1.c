#include <stdio.h>
#define N 1000000

void Selection_Sort(int a[], int x);

int main(){

	int x, i;
	scanf("%d",&x);
	int a[N];
	for(i=0;i<x;i++)
		scanf("%d",&a[i]);
	Selection_Sort(a,x);

	return 0;

}


void Selection_Sort(int a[], int x){

	int i, min, j, tmp;
	for(i=0;i<x-1;i++){
		min=i;
		for(j=i+1;j<x;j++){
			if(a[j]<a[min])
				min=j;
		}
		if(min!=i){
			tmp=a[i];
			a[i]=a[min];
			a[min]=tmp;
		}
	}
	for(i=0;i<x;i++)
		printf("%d\n",a[i]);

}