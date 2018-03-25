#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL tot;

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		tot = 1;
		
		LL n; scanf("%lld", &n);
		for (LL i=2; i*i<=n; ++i) {
			int cnt=0;
			while (n%i == 0) {
				++cnt, n /= i;
			}
			tot *= (1+cnt*2);
		}
		if (n>1) tot *= (1+1*2);
		
		printf("%lld\n", (tot+1)/2);
	} 
}
