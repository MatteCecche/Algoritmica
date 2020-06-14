#include <stdio.h>
#include <stdlib.h>

struct elemento{

	int info;
	struct elemento *right;
	struct elemento *left;

};
typedef struct elemento Node;


Node* crea(Node **t, int el);
Node* inserisce(Node **t, int el);
void ordina(Node *t);


int main(){

	int n, i, x;
	scanf("%d",&n);
	Node *abr=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		inserisce(&abr,x);
	}
	ordina(abr);

	return 0;

}


Node* crea(Node **t, int el){

	Node *aux=(Node *)malloc(sizeof(Node));
	aux->info=el;
	aux->right=NULL;
	aux->left=NULL;	
	
	return aux;

}


Node* inserisce(Node **t, int el){

	if((*t)==NULL) return *t=crea(&(*t),el);
	else if(el > (*t)->info) (*t)->right=inserisce(&(*t)->right,el);
	     else (*t)->left=inserisce(&(*t)->left,el);

	return *t;

}


void ordina(Node *t){

	if(t!=NULL){
		ordina(t->left);
		printf("%d\n",t->info);
		ordina(t->right);
	}

}
