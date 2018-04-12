#include <bits/stdc++.h>
using namespace std;

//~ DirtyHack

const int maxN = 40;

int gcd(int x, int y)
{
	return y==0 ? x : gcd(y, x%y);
}

struct fraction{
	int x, y;
	fraction() = default;
	fraction(int a, int b) {
		x = a, y = b;
		int g = gcd(a, b);
		if (g) x /= g, y /= g;
	}
	bool operator ==(const fraction &f) const {
		return x==f.x && y==f.y;
	}
	bool operator < (const fraction &f) const {
		int lx = x*f.y;
		int rx = f.x*y;
		return lx < rx;
	}
	fraction operator +(const fraction &f) const {
		return fraction(x+f.x, y+f.y);
	}
};

int a[maxN], b[maxN];
vector<fraction> lft, rght;
fraction privot;

void push(vector<fraction> &bucket, int bgn, int end, fraction last)
{
	if (bgn > end) return;
	
	fraction nxt(last.x+a[bgn], last.y+b[bgn]);
	
	if (nxt.y != 0) bucket.push_back(nxt);
	
	push(bucket, bgn+1, end, nxt);
	push(bucket, bgn+1, end, last);
}

bool search(int idx)
{
	int left = 0, right = rght.size()-1;
	while (left <= right)
	{
		int mid = (left+right)/2;
		if (rght[mid] + lft[idx] == privot) return true;
		else if (rght[mid] + lft[idx] < privot) left = mid+1;
		else right = mid-1;
	}
	return false;
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
		privot = fraction(x, y);
		
		for (int i=0; i<n; ++i)
			scanf("%d%d", &a[i], &b[i]);
		
		push(lft, 0, n/2, fraction(0, 0));
		push(rght, n/2+1, n-1, fraction(0, 0));
		
		//~ sort(lft.begin(), lft.end());
		sort(rght.begin(), rght.end());
		
		int cnt = 0;
		for (unsigned i=0; i<lft.size(); ++i) {
			int ix = lft[i].x, iy = lft[i].y;
			fraction icur(ix, iy);
			if (icur == privot) ++cnt;
			
			if (search(i)) ++cnt;
		}
		for (unsigned j=0; j<rght.size(); ++j) {
			int jx = rght[j].x, jy = rght[j].y;
			fraction jcur(jx, jy);
			if (jcur == privot) ++cnt;
		}
		
		printf("%d\n", cnt);
	}
	//~ cout << double(clock())/CLOCKS_PER_SEC << endl;
}
