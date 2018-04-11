#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

// 成也暴力，败也暴力
// 裸折半失败

// 思路过于复杂，
// 学习对分数的处理
// 学习分治的思路

const int maxN = 40;

int gcd(int x, int y)
{
	return y==0 ? x : gcd(y, x%y);
}

int a[maxN], b[maxN];

vector<pi> lft, rght;

void reduce(pi &p)
{
	int g = gcd(p.first, p.second);
	if (g != 0) p.first /= g, p.second /= g;
}

void push(vector<pi> &bucket, int bgn, int end, pi last)
{
	if (bgn > end) return;
	
	pi nxt {last.first+a[bgn], last.second+b[bgn]};
	reduce(nxt);
	
	if (nxt.second != 0) bucket.push_back(nxt);
	
	push(bucket, bgn+1, end, nxt);
	push(bucket, bgn+1, end, last);
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int t; scanf("%d", &t);
	
	while (t--)
	{
		lft.clear(); rght.clear();
		
		int n, x, y; scanf("%d%d%d", &n, &x, &y);
		pi privot {x, y};
		
		for (int i=0; i<n; ++i)
		{
			scanf("%d%d", &a[i], &b[i]);
		}
		
		push(lft, 0, n/2, {0, 0});
		push(rght, n/2+1, n-1, {0, 0});
		
		int cnt = 0;
		for (unsigned i=0; i<lft.size(); ++i) {
			int ix = lft[i].first, iy = lft[i].second;
			pi icur {ix, iy}; reduce(icur);
			if (icur == privot) ++cnt;
		}
		for (unsigned j=0; j<rght.size(); ++j) {
			int jx = rght[j].first, jy = rght[j].second;
			pi jcur {jx, jy}; reduce(jcur);
			if (jcur == privot) ++cnt;
		}
		
		for (unsigned i=0; i<lft.size(); ++i)
		{
			for (unsigned j=0; j<rght.size(); ++j)
			{
				int cx = lft[i].first + rght[j].first;
				int cy = lft[i].second + rght[j].second;
				pi cur {cx, cy}; reduce(cur);
				if (cur == privot) ++cnt;
			}
		}
		printf("%d\n", cnt);
		printf("%f\n", (double)clock()/CLOCKS_PER_SEC);
	}
}
