#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,k,m;
	printf("Please enter the length of the array.\n");
	scanf("%d",&k);
	int A[k];
	
	printf("Please define the content of the array.\n");
	for(i=0;i<k;i++)
	{
		printf("A[%d]=",i);
		scanf("%d",&A[i]);
	}
	/*printf("Examining...\n");
	for(i=0;i<k;i++)
	{
		printf("A[%d]=%d\n",i,A[i]);
	}*/
	printf("\n");
	for(i=0;i<k;i++)
	{
		for(j=0;j<k-1;j++)
		{
			if(A[j]>A[j+1])
			{
				m=A[j];
				A[j]=A[j+1];
				A[j+1]=m;
			}
		}
	}
	printf("The result is below.\n\n");
	for(i=0;i<k;i++)
		{
			printf("A[%d]=%d\n",i,A[i]);
		}
}
