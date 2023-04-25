#include<stdio.h>

int main()
{
	//total memory
	int tm;
	printf("\n Enter memory size : ");
	scanf("%d",&tm);
	
	//array for storing process size
	int a[100];

	//array for storing all process size
	int b[100];

	//start allocating
	int temp=tm;
	int i=0;
	int j=0;
	int total_allocated=0;
	while(temp > 0)
	{
		int ps;
		printf(" Enter Process %d size : ",j+1);
		scanf("%d",&ps);
		b[j++]=ps;
		if(ps<temp)
		{
			a[i++]=ps;
			temp=temp-ps;
		}
		else if(ps==temp)
		{
			a[i++]=ps;
			temp=0;
			break;
			
		}
		else
			break;
		
	}

	total_allocated=tm-temp;
	int p=tm;
	printf("\n Process No.\tRequired Space\tAvailable  \t  Status\n");
	for(int k=0;k<j;++k)
	{
		if(k<i)
		{
			printf("\n %d\t\t %d\t\t %d\t\t Allocated",k+1,b[k],p);
			p=p-b[k];
		}
		else
		{
			printf("\n %d\t\t %d\t\t %d\t\t Not Allocated",k+1,b[k],p);
		}
	}
	printf("\n");
	printf("\n total memory space : %d",tm);
	printf("\n total used memory : %d\n",total_allocated);
	printf(" External Fragmentation space : %d\n\n",temp);
	
}
