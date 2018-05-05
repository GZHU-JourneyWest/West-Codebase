struct _node
{
	double x,y;
	_node()
	{
		x=y=0;
	}
}node[105];
ll n;

ll X[]={0,0,1,-1};
ll Y[]={-1,1,0,0};

double dist(_node a,_node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double jl(_node a)
{
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=dist(a,node[i]);
	}
	
	return sum;
}

double mnth()
{
	srand((unsigned)time(NULL));

	double ans=inf;
	double delta=0.98,T=10; //delta:降温速度 T:初始温度(这2个变量的值不固定 自己找感觉取就好了) 
	_node p=node[1];
	while(T>1e-8)
	{
		
		for(int i=1;i<=10;i++)
		{
			_node s;
			s.x=p.x+T*(rand()%100-50);//要保证正负几率一样 
			s.y=p.y+T*(rand()%100-50);//要保证正负几率一样 
			if(ans>jl(s))
			{
				p=s;
				ans=jl(s);
			}
			else
			{
				double dE=ans-jl(s);
				if(exp(dE/T) > rand()/double(RAND_MAX))
				{
					p=s;
					ans=jl(s);
				}
			}
		}
		T=T*delta;
	}
	return ans;
}

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&node[i].x,&node[i].y);
	}
	ll ans=mnth()+0.5;
	printf("%lld\n",ans);
}
