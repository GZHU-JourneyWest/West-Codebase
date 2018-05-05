struct _x
{
	ll num;  // 边权 
	ll u,v;  // 边的2个端点 
	bool operator <(const _x & other) const{return other.num<num;}

}x[50500];	//边 

ll n,g,A[20500];		// n:点数  g:输入边数  A[]:并查集 

ll ff(ll a)
{
	if(A[a]==a)return a;
	else return A[a]=ff(A[a]);
}

ll kruskal()
{
	ll ans=0,bs=0;  // ans:结果  bs: 连通边数
	sort(x+1,x+1+g);
	for(int i=1;i<=g;i++)
	{
		ll fu,fv;
		fu=ff(x[i].u);
		fv=ff(x[i].v);
		if(fu!=fv)	// 判断是否同一个集合
		{
			A[fu]=fv;
			ans+=x[i].num;
			bs++;
			if(bs==n-1)break;  // 如果 边数=点数-1 说明连通了
			
		}
	}
	return ans;
}
