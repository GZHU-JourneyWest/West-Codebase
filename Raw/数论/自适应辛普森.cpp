double F(double x)
{
	return sin(cos(x));
}

double simpson(double l,double r)
{
	double mid=(l+r)/2;
	return (F(l)+4*F(mid)+F(r))*(r-l)/6;
	
}

double solve(double l,double r,double eps)
{
	double mid=(l+r)/2;
	double st=simpson(l,r),sl=simpson(l,mid),sr=simpson(mid,r);
	if(fabs(sl+sr-st)<=15.0*eps)return  sl+sr+(sl+sr-st) / 15.0;
	return solve(l,mid,eps/2)+solve(mid,r,eps/2);
}

int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		double a,b;
		scanf("%lf%lf",&a,&b);
		printf("%0.1lf\n",fabs(solve(a,b,1e-8)));
	} 
}