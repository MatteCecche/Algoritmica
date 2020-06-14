#include <stdio.h>

int main()

{	int N;
	scanf("%d",&N);
	int a[N];
	int i;
	for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	for(i=N-1;i>=0;i--)
	printf("%d\n",a[i]);

	return 0;

}

