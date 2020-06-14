#include <stdio.h>
#include <stdlib.h>

int somma_dei_primi(int x, int a);

int main()

{	int x;
	scanf("%d",&x);
	int somma = somma_dei_primi(x, 1);
	printf("%d\n",somma);
	return 0;
}

int somma_dei_primi(int x, int a){
	if (x!=0) 
	{
		return a + somma_dei_primi(x-1, a+2);
	}
	else return 0;
}

