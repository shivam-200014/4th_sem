#include<stdio.h>
int main()
{	 //memory space
 	 int ms;
	 printf("\n\nenter the memory space in bytes: ");
	 scanf("%d",&ms);

	 //size of each block
	 int bs;
	 printf("enter the size of each block in bytes: ");
	 scanf("%d",&bs);

	 //number of process
	 int n;
	 printf("enter the number of processes: ");
	 scanf("%d",&n);
	 
	 //array to hold size of each process
	 int ps[n];
	 printf("Enter the memory space required by each process: ");
	 for(int i=0;i<n;i++)
	 	scanf("%d",&ps[i]);

	 //number of block
	 int nb;
	 nb=ms/bs;
	 printf("number of blocks: %d\n",nb);
	 
	 //eval external fragmentation space
	 int ef;
	 ef=ms-(nb*bs);

	 //for internal fragmentation
	 int ifrag=0;

	 int i;
	 int j=0;
	 printf("\nProcess No \t Status \t\t Size of Internal Fragment\n");
	 for(i=0;i<n&&j<nb;i++)
	 {
	  	  //printf("process %d: ",i+1);
		  if(ps[i]<=bs)
		  {
		  	printf("%d\t\t Allocated \t\t %d\n",i+1,bs-ps[i]);
			ifrag=ifrag+(bs-ps[i]);
		  	j++;
		  }
		  else
		  	printf("%d\t\t Not Allocated \n",i+1); 
	 }
	 if(i<n-1)
	 	printf("remaining processes cannot be fit in memory.\n");
	 printf("\nsize of internal fragment:%d\n",ifrag);
	 printf("size of external fragment: %d\n\n",ef);
	 
	 return 0;
}
