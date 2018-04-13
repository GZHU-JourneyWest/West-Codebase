#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll j[4][15];
ll A[11]={0,2,2,2,0,0,0};
ll n=2;
ll num=0;
ll g=0;
void dfs(ll ls,ll hs,ll n,bool k,ll B[])
{
	if(k)
	{
		B[ls-1]--;
		B[ls]--;
		B[ls+1]--;
	}
	
	
	
	
	
	if(ls==n+1)
	{
		
		if(hs==1)
		{
			dfs(1,hs+1,n,1,B);
			dfs(1,hs+1,n,0,B);
		}
		else
		{
			g++;
			cout<<"g:"<<g<<endl;
			bool flag=1;
			for(int i=1;i<=n;i++)
			{
				
				cout<<B[i]<<" ";
				
				
				if(B[i]!=0)
				{
					flag=0;
				}
				
			}
			cout<<endl;
			num+=flag;
			
			
		}
		
		return ;
	}
	dfs(ls+1,hs,n,1,B);
	dfs(ls+1,hs,n,0,B);
	
}
int main()
{
	dfs(0,1,n,0,A);
	cout<<num<<endl;
	
	
	
	
}
