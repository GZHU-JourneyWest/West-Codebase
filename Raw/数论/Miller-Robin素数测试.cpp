#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL mod_pow(LL a, LL b, LL mod)
{
	LL ans = 1, base = a % mod;
	while (b)
	{
		if (b&1) ans *= base, ans %= mod;
		base *= base, base %= mod, b >>= 1;
	}
	return ans;
}

// 独立Miller-Robin测试，返回n是否为质数
bool test(LL n, LL a, LL d)
{
	if (n==2) return true;
	if (n==a) return true;
	if ((n&1)==0) return false;
	while (!(d&1)) d >>= 1;
	LL t = mod_pow(a, d, n);
	while ((d!=n-1) && (t!=1) && t!=(n-1))
	{
		t = t * t % n;
		d <<= 1;
	}
	return (t==n-1 || (d&1));
}

// 判定n是否为素数
bool isprime(LL n)
{
	if (n<2) return false;
	int a[] = {2, 3, 61};  // 更大范围的素数需要更广的测试集
	for (int i=0; i < 3; ++i) if (!test(n, a[i], n-1)) return false;
	return true;
}

int main()
{
	int t;
	while (scanf("%d", &t) == 1)
	{
		int tot = 0;
		while (t--)
		{
			int i; scanf("%d", &i);
			if (isprime(i)) ++tot;
		}
		printf("%d\n", tot);
	}
}
