#include <stdio.h>
#include <stdlib.h>
#define N 10000

struct elemento{

	int x;
	int y;

};
typedef struct elemento coordinate;


int compare(coordinate *a, coordinate *b);

int main(){

	int n, i;
	scanf("%d",&n);
	coordinate *arr;
	arr=(coordinate *)malloc(n*sizeof(coordinate));
	for(i=0;i<n;i++){
		scanf("%d %d",&(arr[i].x),&(arr[i].y));
	}
	qsort(arr,n,sizeof(coordinate),compare);
	for(i=0;i<n;i++)
		printf("%d %d\n",arr[i].x,arr[i].y);

	return 0;

}


int compare(coordinate *a, coordinate *b){

	coordinate *a1=(coordinate*)a;
	coordinate *b1=(coordinate*)b;
	if(a1->x!=b1->x) return a1->x - b1->x;
	else return b1->y - a1->y; 
	
}