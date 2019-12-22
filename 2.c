#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

void main(){
	int m,n,i,j;
	printf("Enter size of matrix\n");
	scanf("%d%d",&m,&n);
	int matrix[m][n];
	int vec[n];
	int res[m];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			matrix[i][j]=rand()%100;
		}
		res[i]=0;
		}

	for(i=0;i<n;i++)
		vec[i]=rand()%100;

	printf("Matrix:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
		}
	printf("Vector:\n");
	for(i=0;i<n;i++)
		printf("%d\n",vec[i]);
	
	//#pragma omp parallel for num_threads(8)
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			res[i]=res[i]+matrix[i][j]*vec[j];
			}
		}
	printf("resultant vector\n");
	for(i=0;i<m;i++)
		printf("%d\n",res[i]);
	}
	
	

	
	

