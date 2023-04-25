#include<stdio.h>
#define INT_MAX 2140000000

int main()

{
	//number of memory block
	int nb;
	printf("\n enter no of memory block : ");
	scanf("%d",&nb);
	
	//number of process
	int np;
	printf("\n enter no of process : ");
	scanf("%d",&np);

	// block array
	int b[nb];
	printf("\n enter size for each memory block : ");
	
	for(int i=0;i<nb;++i)
		scanf("%d",&b[i]);

	//process array
	int p[np];
	printf("\n enter size of each process : ");
	
	for(int i=0;i<np;++i)
		scanf("%d",&p[i]);
	
	
	printf("\n Process No.\tProcess Size\tAllocated Block\n");

	for(int i=0;i<np;++i)
	{
		int k=-1;
		int smallest=INT_MAX;		
			
		for(int j=0;j<nb;++j)
		{
			if(b[j]>=p[i] && smallest > b[j]-p[i])
			{
				smallest=b[j]-p[i];
				k=j;
			}
		}

		if(k!=-1)
		{
			printf(" %d\t\t%d\t\t%d\n",i+1,p[i],k+1);
			b[k]=b[k]-p[i];
		}
		else
			printf(" %d\t\t%d\t\tNot Allocated\n",i+1,p[i]);

	}
	printf("\n");
	

}
