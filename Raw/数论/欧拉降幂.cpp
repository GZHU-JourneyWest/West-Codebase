int Euler(int n)  // 欧拉函数
{
	int ans=n;
	for (int=2; i*i<=n; ++i)
	{
		if (n%i==0)
		{
			ans=ans*(i-1)/i;
			while (n%i==0) n/=i;	
		} 
	}
	if (n>1) ans=ans*(n-1)/n;
	return ans;
}
