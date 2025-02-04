#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento EDL;

void coda(EDL **lista, int x);
int testa(EDL **lIsta, int x);


int main(){

	int n, i, x, q;
	int trovato=0;
	scanf("%d",&n);
	EDL *lista=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		coda(&lista,x);
	}	
	while(!trovato){
		scanf("%d",&x);
		q=testa(&lista,x);
		if(q == -1) trovato=1;
		else printf("%d\n",q);
	}

	return 0;

}


void coda(EDL **lista, int x){

	EDL *corr=*lista;
	EDL *aux=malloc(sizeof(EDL));
	EDL *prec=NULL;
	aux->info=x;
	aux->next=NULL;
	if(*lista == NULL) *lista=aux;
	else {
		while(corr != NULL){
			prec=corr;
			corr=corr->next;
		}
		prec->next=aux;
	}

}

int testa(EDL **lista, int x){

	EDL *corr=*lista;
	EDL *prec=NULL;
	EDL *aux=malloc(sizeof(EDL));
	aux->info=x;
	aux->next=NULL;
	int conta=0;	
	while(corr->info != x && corr != NULL){
		prec=corr;		
		corr=corr->next;
		conta++;
		if(corr == NULL){
			printf("-1\n");		
			return -1; 	
		}
	}
	if(prec != NULL){
		if(corr->next == NULL){
			prec->next=NULL;
			free(corr);
			aux->next=*lista;
			*lista=aux;
		} else {
			prec->next=corr->next;
			free(corr);
			aux->next=*lista;
			*lista=aux;
		}
	return conta;	
	} else return 0;
	
}
