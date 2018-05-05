ll n,m;					// n:节点数  m:通道数 
ll road[1005][1005];	// 最大流 
ll pre[1005];			// 前节点(类似并查集) 
bool mark[1005]; 		// 标记 

bool BFS(ll s,ll t)  // 寻找s-t的路  s:起点 t:终点 
{
     
    queue <ll> Q;
    memset(pre,-1,sizeof(pre));		// 初始化 
    memset(mark,0,sizeof(mark));	// 初始化 
     
    pre[s]=s;		// 起点前向节点设为自己 
    mark[s]=1;		// 标记已通过 
    Q.push(s);		// 放入队列  
     
    ll top;
    while(!Q.empty())
    {
        top=Q.front();
        Q.pop();
        for(int i=s;i<=t;i++)  // 探索s-t的路 
        {
            if(mark[i])continue;	// 标记则不访问 
            if(road[top][i]>0)		// 路径还有流量则放入Q 等待访问 
            {
                pre[i]=top;
                mark[i]=1;
                Q.push(i);
                if(i==t)return 1;	// 已是终点证明存在s-t的路 
            }
        } 
    }
    return 0;  //没有s-t的路则返回0 
}

ll EK(ll s,ll t)
{
    ll maxflow=0,d;  // maxflow:最大流   d:支流 
     
    while(BFS(s,t))
    {
     
        d=inf;  // 初始化 
        for(int i=t;i!=s;i=pre[i])d=min(d,road[pre[i]][i]);  // 回溯得最小剩余流量
        for(int i=t;i!=s;i=pre[i])
        {
            road[pre[i]][i]-=d;	 // 正向流量减少 
            road[i][pre[i]]+=d;  // 反向流量增加
        }
        maxflow+=d;
    }
    return maxflow; 
}

int main()
{
    while(~scanf("%lld%lld",&n,&m))
    {
        memset(road,0,sizeof(road));  // 初始化 
        ll M0;
        scanf("%lld",&M0);
        ll a,b,c;
        for(int i=1;i<=m;i++)
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            road[a][b]=max(road[a][b],c);  // 初始化路的流量 
        }
        ll ans=EK(0,n+1);
        if(M0<ans)ans=M0;  // 题目要求 因为湖(0)的最大流量是M0  
        printf("%lld\n",ans);
    }
}
