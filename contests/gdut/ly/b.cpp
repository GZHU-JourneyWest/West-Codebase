#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 1000100;

LL nonrep[maxN];

bool check(LL num)
{
	bool digit[10] {};
	
	while (num) {
		int cur = num%10;
		if (digit[cur]) return false;
		digit[cur] = true;
		num /= 10;
	}
	return true;
}

void build()
{	
	LL base = 1, gap = 0, tail = 0;
	while (tail<maxN) {
		for (int i=1; i<10 && tail<maxN; ++i)
		{
			for (int j=0; j<=gap && tail<maxN; ++j) 
			{
				LL nxt = i*base+nonrep[j];
				if (check(nxt)) 
					nonrep[++tail] = nxt;
			}
		} 
		base *= 10, gap = tail;
	}
}

int main()
{	
	build();
	
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		printf("%lld\n", nonrep[n]);
	}
} 
