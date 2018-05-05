#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxN = 202;

struct edge
{
	double x1, x2, y; int type;
	bool operator <(const edge& b) const
	{
		return y<b.y;
	}
} e[maxN];

double h[maxN];
double len[maxN<<2]; int cover[maxN<<2];

#define ls (rt<<1)
#define rs ((rt<<1)|1)
void pushup(int rt, int l, int r)
{
	if (cover[rt]>0) len[rt] = h[r] - h[l];
	else
	{
		if (l+r!=1) len[rt] = len[ls] + len[rs];
		else len[rt] = 0;
	}
}

void update(int rt, int l, int r, int p, int q, int v)
{
	if (p<=l&&r<=q) cover[rt] += v;
	else
	{
		int mid = (l+r)/2;
		if (p<mid) update(ls, l, mid, p, min(mid, q), v);
		if (q>mid) update(rs, mid, r, max(mid, p), q, v);
	}
	pushup(rt, l, r);
}

int main()
{
	int kase = 0, n;
	while (scanf("%d", &n)==1 && n)
	{
		if (kase) {
			memset(len, 0, sizeof(len));
			memset(cover, 0, sizeof(cover));
			putchar('\n');
		}
		
		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			double x1, y1, x2, y2; scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			e[res] = {x1, x2, y1, 1}; h[res++] = x1;
			e[res] = {x1, x2, y2,-1}; h[res++] = x2;
		}
		sort(e, e+res);
		sort(h, h+res); res=unique(h, h+res)-h;
		
		double ans = 0;
		for (int i = 0; i < 2*n-1; ++i)
		{
			int p = lower_bound(h, h+res, e[i].x1)-h;
			int q = lower_bound(h, h+res, e[i].x2)-h;
			update(1, 0, res-1, p, q, e[i].type);
			ans += len[1] * (e[i+1].y-e[i].y);
		}
		printf("Test case #%d\n", ++kase);
		printf("Total explored area: %.2f\n", ans);
	}
}
