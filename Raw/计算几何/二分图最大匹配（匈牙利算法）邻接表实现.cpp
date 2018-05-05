bool xz[1050][1050]; // A组成员与B组成员的关系  1:有关系 0:没关系 

ll pt[1050]; 		// 占用B组成员的A组成员编号 
ll use[1050];		// B组某成员是否被占用 
ll m,n;				// m:A组人数  n:B组人数
bool find(ll x)	
{
	for(int i=1;i<=n;i++)  // B组成员编号:[1-n] 
	{
		if(use[i]==1)continue; 
		if(xz[x][i]==1)
		{
			use[i]=1;
			if(pt[i]==0 || find(pt[i])) 
			{
				pt[i]=x; 
				return 1;  
			}
		}
	}
	return 0;
}

int main()
{
	ll a;
	while(~scanf("%lld",&a) && a)
	{
		memset(pt,0,sizeof(pt));
		memset(xz,0,sizeof(xz));
		scanf("%lld%lld",&m,&n);
		while(a--)
		{
			ll p,q;	
			scanf("%lld%lld",&p,&q);
			xz[p][q]=1;
		}
		
		ll num=0;  // 最大匹配数 
		for(int i=1;i<=m;i++)  // A组成员编号:[1-m] 
		{
			memset(use,0,sizeof(use));
			if(find(i)==1)num++;
		}
		printf("%lld\n",num);
	}
}
