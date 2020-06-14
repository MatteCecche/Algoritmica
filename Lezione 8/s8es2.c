#include <stdio.h>
#include <stdlib.h>


struct elemento {

	int info;
	struct elemento *prec;	
	struct elemento *next;

};
typedef struct elemento EDL;

void coda(EDL **lista, EDL **newlista, int x);
void stampa(EDL *lista);


int main(){

	int n, x;
	int i=0;
	scanf("%d",&n);
	EDL *lista=NULL;
	EDL *fine_lista=NULL;
	while(i<n){
		scanf("%d",&x);
		coda(&lista,&fine_lista,x);
		i++;
	}
	stampa(fine_lista);

	return 0;
		
}


void coda(EDL **lista, EDL ** newlista, int x){

	EDL *aux;
	aux=malloc(sizeof(EDL));
	aux->info=x;
	aux->next=NULL;
	aux->prec=NULL;
	if(*lista==NULL){
		*lista=aux;
		*newlista=*lista;
	} else {
		aux->prec=*newlista;
		(*newlista)->next=aux;
		*newlista=aux;
		}

}


void stampa(EDL *lista){

	EDL *corr=lista;
	while(corr != NULL){
		printf("%d\n",corr->info);
		corr=corr->prec;
	}

}
