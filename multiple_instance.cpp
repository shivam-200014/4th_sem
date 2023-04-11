#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> ans;
	
	//number of process
	
	int n=3;
	
	//types of resources
	
	int m=3;
	
	//allocated resources in allocated matrix
	
	int tot_allocated[m];
	for(int i=0;i<m;++i)
		tot_allocated[i]=0;
		
	int allocated[n][m]={{1,2,1},{2,0,1},{2,2,1}};
	
	//maximum requirement by each process in max matrix
	
	int max[n][m]={{2,2,4},{2,1,3},{3,4,1}};
	
	//total resources in system
	
	int total[m]={5,5,5};
	
	//calculation of need matrix
	
	int need[n][m];
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			need[i][j] = max[i][j] - allocated[i][j] ;

			
			tot_allocated[j]+=allocated[i][j];
		}
	}
	

	
	//eval available resources av=tot-allo;
	int available[m];
	for(int i=0;i<m;++i)
	{
		available[i] = total[i]-tot_allocated[i] ;

	}

	
	queue<int> q;
	for(int i=0;i<n;++i)
		q.push(i);
		
	
	while(q.size()!=0)
	{
		int i=q.front();

		
		int flag =1;
		for(int j=0;j<m;++j)
		{
			if(need[i][j]>available[j])
			{
				flag=0;
				break;
			}
		}
		
		if(flag==1)
		{
			//update available resources
			
			for(int j=0;j<m;++j)
			{
				available[j]+=allocated[i][j];
			}
			
			//push in ans
		
			ans.push_back(i);
			
			//remove that process from queue
			
			q.pop();
			
		}
		
		else
		{
			//delete from front add to back of queue
			
			q.pop();
			q.push(i);
		}
	
	
	}
	
	cout<<"\nsystem in safe state\n";
	cout<<"safe sequence is :";
	
	int k=ans.size();
	for(int i=0;i<k-1;++i)
		cout<<"p"<<ans[i]<<"->";
		 
	cout<<"p"<<ans[k-1]<<endl;
	
	
	
}
