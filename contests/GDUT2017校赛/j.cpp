#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 100100;
LL num[maxN];

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			scanf("%lld", &num[i]);
		}
		sort(num, num+n);
		LL sum = accumulate(num, num+n, 0LL);
		
		LL step = 0, extra = 0;
		for (int i=1; i<n; ++i) {
			step += num[i]-num[i-1];
			extra += (num[i]-num[i-1])*(n-i-1);
		}
		step += extra;
		LL final = (sum+step*(n-1))/n;
		printf("%lld %lld\n", step, final);
	}
}
