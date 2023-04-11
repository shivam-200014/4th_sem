#include<stdio.h>

int n,wfg[10][10];


	int check_cycle(int process, int visit[], int stack[])
	{
		 visit[process]=1;
		 stack[process]=1;

		 for(int i=0;i<n;i++)
		 {
		   if(wfg[process][i])
		   {
		     if(visit[i]==0&&check_cycle(i,visit,stack))
		     	return 1;
		     if(stack[i]==1)
		     	return 1;
		   }
		 }

		  stack[process]=0;
		 return 0;
	}


	int deadlock()
	{
	 int visit[n];
	 for(int i=0;i<n;i++)
	 	visit[i]=0;

	 for(int i=0;i<n;i++)
	 {
		  if(visit[i]==0)
		  {
		    int stack[n];
		    for(int t=0;t<n;t++)
			stack[t]=0;
		    if(check_cycle(i,visit,stack))
		    	return 1;
		  }
	 }

	 return 0;

	}


int main()
{
	 printf("number of processes: ");
	 scanf("%d",&n);

	 printf("number of resources: ");
	 int m;
	 scanf("%d",&m);

	 int rag[n][m];
	 for(int i=0;i<n;i++)
	 {
	   for(int j=0;j<m;j++)
	     {
	       rag[i][j]=0;
	     }
	 }

	 for(int i=0;i<n;i++)
	 {
	   for(int j=0;j<n;j++)
	     {
	       wfg[i][j]=0;
	     }
	 }

	 printf("enter edges in the graph:\n");
	 printf("R  P: enter 0:\n");
	 printf("R->P: enter 1:\n");
	 printf("P->R: enter -1:\n");

	 for(int i=0;i<n;i++)
	 {
	  for(int j=0;j<m;j++)
	   scanf("%d",&wfg[i][j]);
	 }



	 for(int i=0;i<n;i++)
	 {
	  for(int j=0;j<m;j++)
	  {
	    for(int k=0;k<n;k++)
	    {
	      if(rag[i][j]==-1&&rag[j][k]==1)
	      	wfg[i][k]=1;
	    }
	  }
	 }


	 if(deadlock()==1)
	 	printf("deadlock detected\n");
	 else
	 	printf("No deadlock detected\n");
	 return 0;

}


