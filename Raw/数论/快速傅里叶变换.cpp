struct Complex
{
	double a,b;
	Complex(){}
	Complex(double aa,double bb):a(aa),b(bb){}
	Complex operator +(Complex p)
	{
		double c=p.a,d=p.b;
		return Complex(a+c,b+d);
	}
	Complex operator *(Complex p)
	{
		double c=p.a,d=p.b;
		return Complex(a*c-b*d,b*c+a*d);
	}
	Complex operator -(Complex p)
	{
		double c=p.a,d=p.b;
		return Complex(a-c,b-d);
	}

};
struct FFT
{
	Complex _P[MAXN];
	void build(Complex P[],ll n,ll m,ll curr,ll &cnt)
	{
		if(m==n)_P[curr]=P[cnt++];
		else
		{
			build(P,n,m*2,curr,cnt);
			build(P,n,m*2,curr+m,cnt);
		}
	}
	void solve(Complex P[],ll n,ll oper)
	{
		ll cnt=0,m,m2;
		double p0;
		build(P,n,1,0,cnt);
		for(ll i=0;i<n;i++)P[i]=_P[i];
		for(ll d=0;(1<<d)<n;d++)
		{
			m=1<<d;
			m2=m*2;
			p0=PI/m*oper;
			Complex unit_p0=Complex(cos(p0),sin(p0));
			for(ll i=0;i<n;i+=m2)
			{
				Complex unit=Complex(1,0);
				for(ll j=0;j<m;j++)
				{
					Complex &P1=P[i+j+m];
					Complex &P2=P[i+j];
					Complex t=unit*P1;
					P1=P2-t;
					P2=P2+t;
					unit=unit*unit_p0;
				}
			}
		}
	}
}F;

Complex p1[MAXN],p2[MAXN];
char s1[MAXN],s2[MAXN];

void process()
{
	memset(p1,0,sizeof(p1));
	memset(p2,0,sizeof(p2));
	ll l1=strlen(s1),l2=strlen(s2);
	for(ll i=0;i<l1;i++)p1[i].a=(s1[l1-i-1]-'0');
	for(ll i=0;i<l2;i++)p2[i].a=(s2[l2-i-1]-'0');
	F.solve(p1,8192,1);
	F.solve(p2,8192,1);
	for(ll i=0;i<8192;i++)p1[i]=p1[i]*p2[i];
	F.solve(p1,8192,-1);
	ll p=0;
	for(ll i=0;i<8192;i++)
	{
		p1[i].a/=8192;
		ll d=p1[i].a;
		if(d-p1[i].a>0.5)d--;
		if(p1[i].a-d>0.5)d++;
		d+=p;
		p=d/10;
		d%=10;
		p1[i].a=d;
	}
	bool flag=0;
	for(ll i=8191;i>=0;i--)
	{
		if(p1[i].a>=0.5)flag=1;
		if(flag)printf("%.0lf",p1[i].a);
	}
	if(flag==0)printf("0\n");
	else printf("\n");
	
}

int main()
{
	while(~scanf("%s%s",s1,s2))
	{
		process();	
	}
}