#include<stdio.h>

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

		for(int j=0;j<nb;++j)
		{
			if(p[i] <= b[j])
			{
				k=j;
				b[j]=b[j]-p[i];
				break;
			}
		}

		if(k!=-1)
			printf(" %d\t\t%d\t\t%d\n",i+1,p[i],k+1);
		else
			printf(" %d\t\t%d\t\tNot Allocated\n",i+1,p[i]);

	}
	printf("\n");
	

}
