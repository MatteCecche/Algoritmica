#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Ric_Bin(char **a, int sx, int dx, char *b);

int main(){

	int x, y, i;
	int trovato=0;
	char *b=NULL;
	char **a;
	scanf("%d",&x);
	a=(char **)malloc(x*sizeof(char *));
	for(i=0;i<x;i++){
		a[i]=(char *)malloc(101*sizeof(char));
		scanf("%s",a[i]);
	}
	x=strlen(a)-1;
	while(!trovato){
		scanf("%d",&y);
		if(y==1){
			scanf("%s",b);
			printf("%d\n",Ric_Bin(a,0,x,b));
		} else trovato=1;
	}

	return 0;

}


int  Ric_Bin(char **a, int sx, int dx, char *b){

	if (sx>dx) return -1;
	if(sx==dx){
		if(!strcmp(b,a[sx])) return sx;
		else -1;
	}
	int pos=sx+dx/2;
	if(!strcmp(b,a[pos])) return pos;
	if(strcmp(b,a[pos])) return Ric_Bin(a,sx,pos-1,b);  
    else return Ric_Bin(a,pos+1,dx,b);
    
}