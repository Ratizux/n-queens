#include <cstdio>
#include <iostream>
using namespace std;

int n,m,x[100]={},ans=0;

bool rlock[100]={},slock[100]={},slockr[100]={};

void dfs(int line,int row)
{
	if(rlock[row]||slock[line+row]||slockr[line-row+m])
	return;
	
	x[line]=row;
	
	if(line==m)
	{
		ans++;
		if(ans<=3)
		{
			for(int i=0;i<n;i++)
			{
				cout<<x[i]+1<<" ";
			}
			cout<<endl;
		}
	}
	
	rlock[row]=true;
	slock[line+row]=true;
	slockr[line-row+m]=true;
	for(int i=0;i<n;i++)
	{
		dfs(line+1,i);
	}
	rlock[row]=false;
	slock[line+row]=false;
	slockr[line-row+m]=false;
	
	return;
}

int main()
{
	cin>>n;
	m=n-1;
	for(int i=0;i<n;i++)
	{
		dfs(0,i);
	}
	cout<<ans<<endl;
}
