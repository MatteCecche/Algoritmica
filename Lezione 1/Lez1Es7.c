#include <stdio.h>

int tswap(int *x, int *y, int *z);

int main()

{	int x,y,z;
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	tswap(&x,&y,&z);
	printf("%d\n",x);
	printf("%d\n",y);
	printf("%d\n",z);

	return 0;

}

int tswap(int *x,int *y,int *z)

{	int temp;
	int temp1;
	temp=*x;
	temp1=*z;
	*x=temp1;
	temp1=*y;
	*y=temp;
	*z=temp1;

	return 0;
}