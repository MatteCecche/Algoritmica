#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento {

	char *a;
	int contatore;
};
typedef struct elemento arr; 


int compare(const void *x, const void *y);
int compare2(const void *x, const void *y);
void frequenza(arr *array, int n, int k);
void stampa(arr *array, int k);

int main(){

	int n, k, i;
	scanf("%d",&n);
	scanf("%d",&k);
	arr *array;
	char *w;
	array=(arr *)malloc(n*sizeof(arr));
	for(i=0;i<n;i++){
		w=(char *)malloc(101*sizeof(char));
		scanf("%s",w);
		array[i].a=w;
	}
	qsort(array,n,sizeof(arr),compare);
	frequenza(array,n,k);
	qsort(array,n,sizeof(arr),compare2);
	stampa(array,k);

	return 0;
}




int compare(const void *x, const void *y){

	arr *x1=(arr *)x;
	arr *y1=(arr *)y;
	return strcmp(x1->a,y1->a);
}


void frequenza(arr *array, int n, int k){

	int conta=1;
	int i;
	for(i=0;i<n-1;i++){
		if(strcmp(array[i].a,array[i+1].a)==0) conta++;
		else {
			array[i].contatore=conta;
			conta=1;
		}
	}
} 


int compare2(const void *x, const void *y){

	arr *x1=(arr *)x;
	arr *y1=(arr *)y;
	return (x1->contatore-y1->contatore);
}


void stampa(arr *array, int k){

	int i=0;
	int conta=0;
	while(conta<k){
		if(strcmp(array[i].a,array[i+1].a)!=0){
			printf("%s\n",array[i].a);
			conta++;
		}
		i++;
	}

}

