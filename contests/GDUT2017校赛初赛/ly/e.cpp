#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		char ch; scanf(" %c", &ch);
		LL k, t; scanf("%lld%lld", &k, &t);
		k %= 26, t %= 26;
		printf("%c\n", char((ch-'a'+k*t)%26+'a'));
	}
}

