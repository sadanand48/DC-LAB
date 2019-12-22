#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int factorial(int n){
	int i,fact=1;
	if(n==0||n==1)
		return 1;
	for(i=2;i<=n;i++)
		fact=fact*i;
	return fact;
}

void main(){
	int n,i;
	scanf("%d",&n);
	int x[n];
	for(i=0;i<n;i++)
		x[i]=factorial(i);

	#pragma omp parallel for firstprivate(x)
	for(i=1;i<n;i++)
		x[i]=x[i-1]*i;
	
	printf("Factorial Table:\n");
	for(i=0;i<n;i++)
		printf("x[%d]=%d\n",i,x[i]);
	}
