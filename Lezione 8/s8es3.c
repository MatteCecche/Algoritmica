#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *next;

};
typedef struct elemento ElementoDiLista;

void Inserisci(ElementoDiLista **lista, int el);
int Cercare(ElementoDiLista *lista, int el, ElementoDiLista **listaris); 
void Riposiziona(ElementoDiLista **lista, int el);
void stampa(ElementoDiLista *lista);

int main(){

	int n, x, i;
	int trovato=1;
	ElementoDiLista *lista=NULL;
	ElementoDiLista *listaris=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		Inserisci(&lista,x);
	}
	while(trovato!=0){
		scanf("%d",&x);
		trovato=Cercare(lista,x,&listaris);
		if(trovato!=0) Riposiziona(&lista,x);
	}
	stampa(listaris);

	return 0;

}


void Inserisci(ElementoDiLista **lista, int el){

ElementoDiLista *corr=*lista;
	ElementoDiLista *aux=malloc(sizeof(ElementoDiLista));
	aux->info=el;
	aux->next=NULL;
	if(corr==NULL) *lista=aux;
	else {
		while(corr->next!=NULL)
			corr=corr->next;
		corr->next=aux;
	}
}


int Cercare(ElementoDiLista *lista, int el, ElementoDiLista **listaris){

	int trovato=0;
	int i=0;
	ElementoDiLista *corr;
	corr=lista;
	while(corr!=NULL && !trovato){
		if(corr->info==el){
			Inserisci(&listaris,i);
			trovato=1;
		} else {
			corr=corr->next;
			i++;
		}
	}

	return trovato;
}


void Riposiziona(ElementoDiLista **lista, int el){

	ElementoDiLista *aux=malloc(sizeof(ElementoDiLista));
	aux->info=el;
	aux->next=NULL;
	ElementoDiLista *corr;
	ElementoDiLista *prec=NULL;
	corr=*lista;
	if(corr!=NULL){
		while(corr!=NULL && corr->info!=el){
			prec=corr;
			corr=corr->next;
		}
		if(corr!=NULL){
			if(prec==NULL){
				*lista=corr->next;
				free(corr);
			} else {
				if(corr->next==NULL){
					prec->next=NULL;
					free(corr);
				} else {
					prec->next=corr->next;
					free(corr);
				}
			}
		}
	}
	aux->next=*lista;
	*lista=aux;
}


void stampa(ElementoDiLista *lista){

	ElementoDiLista *corr=lista;
	while(corr!=NULL){
		printf("%d\n",corr->info);
		corr=corr->next;
		free(corr);
	}
}