struct _node
{
	ll v,w;  // v:点的编号 w:权值
	_node(ll a=0,ll b=0){v=a;w=b;}
	bool operator <(const _node & other)const{return other.w<w;}	
};

vector<_node> A[10500];
bool mark[10500];
ll dis[10500];

void dlsj(ll n)  // n个节点
{
	fill(dis,dis+10500,inf);
	fill(mark,mark+10500,0);
	priority_queue<_node> Q; 
	ll v,v1;
	_node top;
	
	dis[0]=0;  // 这题目0是起点
	Q.push(_node(0,0));	
	
	while(!Q.empty())
	{
		top=Q.top();v=top.v;Q.pop();
		if(mark[v])continue;	
		mark[v]=1;				
		for(int i=0;i<A[v].size();i++)  // 遍历v的连通点
		{
			if(mark[A[v][i].v])continue; 
			v1=A[v][i].v;	
			if(dis[v1]>dis[v]+A[v][i].w)	
			{
				dis[v1]=dis[v]+A[v][i].w;
				Q.push(_node(v1,dis[v1]));
			}
		}
	}
}
