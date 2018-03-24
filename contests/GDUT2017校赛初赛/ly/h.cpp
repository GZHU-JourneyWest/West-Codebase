#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 10086;

int tail;
LL fib[maxN];

int main()
{
	fib[1] = 1, fib[2] = 2; tail = 3;
	for (int i = 3; fib[i-1]<=1e18; ++i)
		fib[i] = fib[i-1] + fib[i-2], ++tail;
	
	int T; scanf("%d", &T);
	while (T--)
	{
		LL n; scanf("%lld", &n);
		int pos = lower_bound(fib, fib+tail, n)-fib;
		if (fib[pos] > n) --pos;
		printf("%d\n", pos);
	}
}
