#include <bits/stdc++.h>
using LL = long long;
using namespace std;

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		long long l, r; scanf("%lld%lld", &l, &r);
	
		long long ans = 0;
		
		bool flag = true;
		for (LL i=30; i>=0; --i) {
			LL privot = 1LL<<i;
			
			cout << i << ' ' << (r&privot ? 1 : 0) << endl;
			
			if (flag) {
				if ((l&privot) == (r&privot)) {
					ans = ans*2+((l&privot) ? 1:0);
				}
				else {
					ans = ans*2;
					flag = false;
				}
			} 
			else {
				ans = ans*2+1;
			}
		}
		printf("%lld\n", ans);
	}
}
