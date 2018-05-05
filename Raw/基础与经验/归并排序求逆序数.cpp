ll A[50005],sum=0;
void merge(ll A[],ll l1,ll r1,ll l2,ll r2)	
{
	ll T[50005];
	ll _l1=l1;	
	ll index=0;	
	while(l1<=r1 && l2<=r2)	
	{
		if(A[l1]>A[l2])	
		{
			T[index++]=A[l2++];		
			sum=sum+r1-l1+1;		
		}
		else T[index++]=A[l1++];
	}
	
	while(l1<=r1)T[index++]=A[l1++];	
	while(l2<=r2)T[index++]=A[l2++];
	for(int i=0;i<index;i++)A[_l1+i]=T[i];
}

void mergesort(ll A[],ll l,ll r)
{
	if(l<r) 
	{
		mergesort(A,l,(l+r)/2);
		mergesort(A,(l+r)/2+1,r);
		merge(A,l,(l+r)/2,(l+r)/2+1,r);
	}
}

int main()
{
	ll n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&A[i]);
	mergesort(A,1,n);
	printf("%lld\n",sum);
}
