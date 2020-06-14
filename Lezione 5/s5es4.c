#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void exchange(int* a, int* b);
int distribuzione(int a[], int sx, int px, int dx);
void quicksort(int a[], int sx, int dx);
int legge(int **a, int *len);


int main(){
  
  int i, n, *A;
  if( legge(&A, &n)) return 1;
  quicksort(A, 0, n-1);
  for(i=0;i<n;i++) 
    printf("%d ", A[i]);
  printf("\n");

  return 0;

}

void exchange(int* a, int* b){
    
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int distribuzione(int a[], int sx, int px, int dx){ 
  
  int j;
  int x=a[dx];
  int i=sx-1;
  int y=i;
  for(j=sx;j<=dx-1;j++)
    if(a[j]<x){
      i++;
      y=i;
      exchange(&a[i],&a[j]);
    }
    else if(a[j]==x){
      y++;
      exchange(&a[y],&a[j]);
    }
  exchange(&a[i+1],&a[dx]);
  return i+1;
}

void quicksort(int a[], int sx, int dx){
  
  int perno, pivot;
  if(sx<dx){
    pivot=dx;
    perno=distribuzione(a,sx,pivot,dx);
    quicksort(a,sx,perno-1);
    quicksort(a,perno+1,dx);
    
  }

}


int legge(int **a, int *len){

  int i;
  scanf("%d",len);
  if(*len<=0) return 1;
  *a=(int *)malloc(*len*sizeof(int));
  if(*a==NULL) return 1;
  for(i=0;i<*len;i++) 
	  scanf("%d",(*a)+i);
  
  return 0;

}