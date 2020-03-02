"use strict"

let n,m,ans=0,x=[],rlock=[],slock=[],slockr=[];

n=13;
m=n-1;

for(let i=0;i<n;i++)
{
	dfs(0,i);
}

document.write(ans);

function dfs(line,row)
{
	if(rlock[row]===true || slock[line+row]===true || slockr[line-row+m]===true)
	return;

	x[line]=row;
	
	if(line===m)
	{
		ans++;
		if(ans<=3)
		{
			for(let i=0;i<n;i++)
			{
				document.write(x[i]+1 + " ");
			}
			document.write("<br/>");
		}
	}

	rlock[row]=true;
	slock[line+row]=true;
	slockr[line-row+m]=true;

	for(let i=0;i<n;i++)
	{
		dfs(line+1,i);
	}
	
	rlock[row]=false;
	slock[line+row]=false;
	slockr[line-row+m]=false;
}
