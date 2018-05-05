// 周赛虫洞穿越 
#include<bits/stdc++.h>
#define inf 1000000000000
using namespace std;
typedef long long ll;

ll n,m,w;  // n:点数  m:正权边数  w:负权边数 
ll d[2505];  // 起点到某点的最短距离 
struct _node
{
	ll v,dis;  // v:连通点  dis:权值
	_node(ll a=0,ll b=0){v=a;dis=b;}
};

vector<_node> V[2505];

bool bm(ll s)  //1:表示无负环 0:表示有负环 
{
	fill(d,d+2505,inf);
	d[s]=0;
	for(int i=1;i<=n;i++)
	{
		for(int u=1;u<=n;u++)
		{
			for(int t=0;t<V[u].size();t++)
			{ 
				ll v=V[u][t].v;
				ll dis=V[u][t].dis;
				d[v]=min(d[v],d[u]+dis);
			}
		}
	}
	for(int u=1;u<=n;u++)
	{
		for(int t=0;t<V[u].size();t++)
		{
			ll v=V[u][t].v;
			ll dis=V[u][t].dis;
			if(d[u]+dis<d[v])return 0;	 
		}
	}
	return 1;
}

int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&m,&w);
		for(int i=1;i<=n;i++)V[i].clear();
		while(m--)	 
		{
			ll a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			V[a].push_back(_node(b,c));
			V[b].push_back(_node(a,c));
		}
		while(w--)
		{
			ll a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			V[a].push_back(_node(b,-c));
		}
		if(bm(1))printf("NO\n");
		else printf("YES\n");
	}
}
