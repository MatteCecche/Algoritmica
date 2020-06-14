#include <stdio.h>
#define N (10)

void minmax(int a[N],int dim,int *min,int *max);

int main()

{	int a[N];
	int i;
	int min;
	int max;
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	minmax(a,N,&min,&max);
	printf("%d\n",min);
	printf("%d\n",a[min]);
	printf("%d\n",max);
	printf("%d\n",a[max]);

	return 0;

}


void minmax(int a[N],int dim,int *min,int *max)

{	int i;
	*min=0;
	*max=0;
	for(i=0;i<dim;i++){
		if(a[i]<a[*min]) *min=i;
		if(a[i]>a[*max]) *max=i;
	}
}