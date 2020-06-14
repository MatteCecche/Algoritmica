#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento1 {

	int x;
	int y;
	int c;

};
typedef struct elemento1 tripla;



int compare(const void *q, const void *p);
int quesito(tripla **a, int n, int x1, int y1, int x2, int y2);



int main(){

	int n, m, i;
	int x1, y1, x2, y2;
	scanf("%d %d",&n,&m);
	tripla **a=malloc(n*sizeof(tripla*));
	for(i=0;i<n;i++){
		tripla * pnt=malloc(sizeof(tripla));		
		scanf("%d %d %d",&(pnt->x),&(pnt->y),&(pnt->c));
		a[i]=pnt;
	}
	qsort(a,n,sizeof(tripla *),compare);
	for(i=0;i<m;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%d\n", quesito(a,n,x1,y1,x2,y2));
	}


	return 0;

}


int compare(const void *q, const void *p){

	const tripla *q1=*(const tripla **)q;
	const tripla *p1=*(const tripla **)p;
	return (q1->c - p1->c);

}



int quesito(tripla **a, int n, int x1, int y1, int x2, int y2){

	int i;
	int conta=0;
	int ult_col=-1;
	for(i=0;i<n;i++){	
		if(x1 <= a[i]->x && a[i]->x <= x2){		
			if(y1 <= a[i]->y && a[i]->y <= y2){		
						if(a[i]->c != ult_col){
							conta++;
							ult_col=a[i]->c;
						}
			}
		}
	}
	
	return conta;

}		
