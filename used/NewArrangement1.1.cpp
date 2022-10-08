#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,k,m,pm;
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
	for(i=0;i<k-1;i++)
	{
		m=A[i];
		pm=i;
		for(j=i+1;j<k;j++)
		{
			if(A[j]<m)
			{
				m=A[j];
				pm=j;
			}
		}
		A[pm]=A[i];
		A[i]=m;
	}
	printf("The result is below.\n");
	for(i=0;i<k;i++)
		{
			printf("A[%d]=%d\n",i,A[i]);
		}
	system("pause");
	return 0;
}
