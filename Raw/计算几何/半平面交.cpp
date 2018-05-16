double zero(double x)
{
	if(x>0)return x<eps;
	else return -x<eps;
}

double _sign(double x)
{
	if(x>eps)return 1;
	else
	{
		if(x<-eps)return 2;
		else return 0;
	}
} 

struct point //点结构体 
{
	double x,y;
	point(){};
	point(double xx,double yy)
	{
		x=xx;
		y=yy;
	}
};

//这里用b-a的矢量的左侧来表示一个半平面 
struct line	//直线结构体 
{
	point a,b;
	line(){};
	line(point aa,point bb)
	{
		a=aa;
		b=bb;
	}
	void set(point aa,point bb)
	{
		a=aa;
		b=bb;
	}
};

double xmult(point p1,point p2,point p0) //计算向量p0->p1 和 p2->p0的叉乘  
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double dmult(point p1,point p2,point p0) //计算向量p0->p1 和 p2->p0的点乘 
{
	return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}

inline bool satisfy(point p,line l)//返回解析: 1的话 点p在向量l.a->l.b的左侧(包括在直线l.a->l.b上)
				   // 	       0的话 点p在向量l.a->l.b的右侧
{
	//Xmult(p,l.b,l.a) 正的话点p在向量l.a->l.b的右侧
	//		   0的话点p与在直线l.a->l.b上
	//		   负的话点p在向量l.a->l.b的左侧 
	return _sign(xmult(p,l.b,l.a))!=1;
}

ll sign(line a,line b)	//向量b在a的左侧及a,b反向则返回 2   b在a右侧返回1  a,b同向返回0; 
{
	point aa,bb;
	aa.x=a.b.x-a.a.x;
	aa.y=a.b.y-a.a.y;
	bb.x=b.b.x-b.a.x;
	bb.y=b.b.y-b.a.y;
	return _sign(atan2(aa.y,aa.x)-atan2(bb.y,bb.x));
}

point cross(line a,line b) //求直线a,b交点 共线出错
{
	double k=xmult(b.a,a.a,b.b);
	k=k/(k-xmult(b.a,a.b,b.b));
	point ans=a.a,pans;
	pans.x=(a.b.x-a.a.x)*k;
	pans.y=(a.b.y-a.a.y)*k;
	ans.x+=pans.x;
	ans.y+=pans.y;
	return ans;
}

bool cmp(line a,line b)} //用于sort的比较函数comp，作极角排序 
{
	ll res=sign(a,b);
	return res==0?satisfy(a.a,b):(res==2);
}

void intersection(ll n,line *l,ll &ansn,point *p) //计算半平面交
{
	ansn=0;
	sort(l,l+n,cmp);
	deque<line> Q;
	deque<point> ans;
	Q.push_back(l[0]);
	for(int i=1;i<n;i++)
	{
		if(sign(l[i],l[i-1])==0)continue;
		while(ans.size()>0 && (!satisfy(ans.back(),l[i])))
		{
			ans.pop_back();
			Q.pop_back();
		}
		while(ans.size()>0 && (!satisfy(ans.front(),l[i])))
		{
			ans.pop_front();
			Q.pop_front();
		}
		ans.push_back(cross(Q.back(),l[i]));
		Q.push_back(l[i]);
	}
	
	while(ans.size()>0 && (!satisfy(ans.back(),Q.front())))
	{
		ans.pop_back();
		Q.pop_back();
	}
	while(ans.size()>0 && (!satisfy(ans.front(),Q.back())))
	{
		ans.pop_front();
		Q.pop_front();
	}
	ans.push_back(cross(Q.back(),Q.front()));
	ansn=ans.size();
	ll i=0;
	for(deque<point>::iterator it=ans.begin();it!=ans.end();it++,i++)
	{
		p[i]=*it;
	}
	
}

double polygon_area(int n,point *p)
{
	double area=0;
	for(int i=1;i<n-1;i++)
	{
		area+=xmult(p[i],p[i+1],p[0]);
	}
	return area/2.0;
}

//这上面我是直接抄模板的 

line A[1050];
point K[1050];
int main()
{
	int n=7;
	double x1,x2,x3,x4;
	double y1,y2,y3,y4;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
	{
		point a(x3,y3),b(x4,y3),c(x4,y4),d(x3,y4);
		point e(x1,y1),f(x1,y2),g(x2,y1); 

		A[0].set(a,b);
		A[1].set(b,c);
		A[2].set(c,d);
		A[3].set(d,a);
		A[4].set(e,f);
		A[5].set(f,g);
		A[6].set(g,e);
		
		if(satisfy(g,A[4])==0)A[4].set(f,e);
		if(satisfy(e,A[5])==0)A[5].set(g,f);
		if(satisfy(f,A[6])==0)A[6].set(e,g);

		ll ans=0;
		point WW[1000];
		intersection(7,A,ans,WW);//这些线的方向向量的左侧(包括这线)的交集就是所求面积,把点集返回到WW中,通过下面的函数求解面积
		printf("%0.8lf\n",polygon_area(ans,WW));

	}
}