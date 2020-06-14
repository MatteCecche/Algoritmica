#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento EDL;

void coda(EDL **lista, int el);
int conta(EDL **lista, int el);
void stampa(EDL *lista);
int cancella(EDL **lista, int media);


int main(){

	int n, x;
	int i=0;
	int somma=0;
	EDL *lista=NULL;
	scanf("%d",&n);
	while(i<n){
		scanf("%d",&x);
		if(i==n-1) somma=conta(&lista,x);
		else coda(&lista,x);
		i++;
	}	
	int media=somma/n;
	printf("%d\n",media);
	stampa(lista);
	cancella(&lista,media);
	
	return 0;

}


void coda(EDL **lista, int el){

	EDL *corr=*lista;
	EDL *aux=malloc(sizeof(EDL));
	aux->info=el;
	aux->next=NULL;
	if(corr==NULL) *lista=aux;
	else {
		while(corr->next!=NULL)
			corr=corr->next;
		corr->next=aux;
	}

}


int conta(EDL **lista, int el){

	EDL* corr=*lista;
	EDL* aux=(EDL *)malloc(sizeof(EDL));
	aux->info=el;
	aux->next=NULL;
	int somma=0;
	while(corr->next!=NULL){
		somma=somma + corr->info;			
		corr=corr->next;
		}	
	somma+=corr->info+el;	
	corr->next=aux;

	return somma;

}


void stampa(EDL *lista){

	EDL *corr=lista;
	while(corr->next!=NULL){		
		printf("%d ",corr->info);
		stampa(corr->next);
	}
	printf("%d\n",corr->info);

}



int cancella(EDL **lista, int media){
		
	EDL *corr=*lista;
	EDL *prec=NULL;
	EDL *aux=NULL;
	while(corr!=NULL){
		if(corr->info <= media){
			if(prec==NULL){
				prec=corr;
				free(prec);				
				return cancella(&corr->next,media);
			} else {
				aux=corr;
				corr=corr->next;
				free(aux);
				prec->next=corr;
			}
		} else {
			printf("%d ",corr->info);
			return cancella(&corr->next,media);
		}
	}

	return 0;
}		
