#include<bits\stdc++.h>

using namespace std;
typedef long long ll; 
ll A[1050];
ll B[1050];

int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		ll n,m;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&A[i]); 
			B[i]=B[i-1]^A[i];
		}
		
	
		
		scanf("%lld",&m);
		while(m--)
		{
			ll a,length=1;
			scanf("%lld",&a);
			ll mini=100000000;
			for(ll i=0;i<=n-1;i++)
			{
				for(ll t=i+1;t<=n;t++)
				{
					
					if(abs((B[t]^B[i])-a)<mini)
					{
						mini=abs((B[t]^B[i])-a);
						
						length=t-i;
						
						
					}
					else
					{
						if(abs((B[t]^B[i])-a)==mini)
						{
							length=max(length,t-i);
							
							
						}
						
					}
					
				}
				
				
			}
			
			
			printf("%lld\n",length);
			
			
			
		}
		
		printf("\n");
	}
	
	
	
}
