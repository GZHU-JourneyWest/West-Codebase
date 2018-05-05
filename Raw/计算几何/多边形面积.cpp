struct _xl   //向量
{
	double x,y;	
	friend double xx(_xl a,_xl b) //叉乘
	{
		return a.x*b.y-a.y*b.x;
	}
} xl[105];

int main()
{
	ll n;
	while(~scanf("%lld",&n) && n)
	{
		double sum=0;
		for(int i=1;i<=n;i++)scanf("%lf%lf",&xl[i].x,&xl[i].y); 
		//题目说了 按逆时针输入了 (逆时针返回正值 顺时针返回负值)
		
		for(int i=1;i<=n;i++)
		{
			if(i==n) sum=sum+xx(xl[i],xl[1]);
			else sum=sum+xx(xl[i],xl[i+1]);
		} 
		sum=sum*0.5;
		printf("%0.1lf\n",sum);
	}	
}
