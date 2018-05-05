ll rd[205],weight[205],n,m;		
vector<ll> V[205];

bool tppx()	
{
	priority_queue<ll> Q;
	for(ll i=1;i<=n;i++)if(rd[i]==0) Q.push(i);
	ll k=n;
	while(!Q.empty())
	{
		ll top=Q.top();
		Q.pop();
		weight[top]=k--;	
		for(ll i=0;i<V[top].size();i++)
		{
			rd[V[top][i]]--;
			if(rd[V[top][i]]==0)Q.push(V[top][i]);
		}
	}

	if(k==0)return 1;
	else return 0;
}

int main()  
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		memset(rd,0,sizeof(rd));
		for(int i=1;i<=n;i++)V[i].clear();
		scanf("%lld%lld",&n,&m);
		while(m--)
		{
			ll a,b;
			scanf("%lld%lld",&a,&b);	
			rd[a]++;	 
			V[b].push_back(a);
		}
		if(tppx())
		{
			for(int i=1;i<=n;i++)
			{
				printf("%lld",weight[i]);
				if(i==n)printf("\n");
				else printf(" "); 
			}
		}
		else printf("-1\n");
	}
}
