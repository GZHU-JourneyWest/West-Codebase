#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--) 
	{
		long long l,r;
		int num1=0,num2=0;
		scanf("%lld%lld",&l,&r);
		long long temp1=l,temp2=r;
		while(temp1)
		{
			temp1>>=1;
			num1++;	
		} 
		while(temp2)
		{
			temp2>>=1;
			num2++; 
		}
		if(num1==num2){
			// long long temp1=l,temp2=r;
			long long temp3 = l ^ r;
			int cnt = 0;
			while (temp3) {
				temp3 >>= 1; cnt++;
			}
			int wei = cnt;
			long long ans=0;
			while(wei--)
			{
				ans<<=1;
				ans++;	
			} 
			ans |= r;
			printf("%lld\n",ans);
		}
		else{
			int wei=max(num1,num2);
			long long ans=0;
			while(wei--)
			{
				ans<<=1;
				ans++;	
			} 
			printf("%lld\n",ans);
		}
	}
}
