struct _node
{
	ll x,y;
}node[100050],A[100050];

bool cmpy(_node a,_node b)
{
	return a.y<b.y;
} 

double dis(_node a,_node b)
{
	return	sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double solve(ll l,ll r)
{
	double d=inf;
	ll v=0,mid;
	if(l==r)return inf;
	
	mid=(l+r)/2;
	d=min(solve(l,mid),solve(mid+1,r));
	for(ll i=mid;i>=l&&node[mid].x-node[i].x<d;i--)A[v++]=node[i];
	for(ll i=mid+1;i<=r&&node[i].x-node[mid].x<d;i++)A[v++]=node[i];

	sort(A,A+v,cmpy);
	for(ll i=0;i<v;i++)
	{
		for(ll t=i+1;t<v && A[t].y-A[i].y<d;t++)
		{
			d=min(d,dis(A[i],A[t]));
		}
	}
	return d;
}

int main()  
{
	ll n;
	scanf("%lld",&n);
	ll sum=0,a;
	for(ll i=0;i<n;i++)
	{
		scanf("%lld",&a);
		sum=sum+a;
		node[i].x=i+1;  // 如果x没从小到大排序 那么要先按x从小到大的顺序排序node
		node[i].y=sum;
	}
	double d=solve(0,n-1);  // 这就是结果了 
	ll ans=ceil(d*d);								// 以下2步都只是处理误差 
	if(fabs(sqrt(ans)-d)>fabs(sqrt(ans-1)-d))ans--; // 精度误差

	printf("%lld\n",ans);
}
