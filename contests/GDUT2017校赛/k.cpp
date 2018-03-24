#include <bits/stdc++.h>
using namespace std;

const int maxN = 100100;

char origin[maxN];
string line[maxN], ans;

void solve(int n)
{
	ans.clear();
	if (n == 1) {
		ans = string(origin);
		return;
	}
	
	for (int i=0; i<n; ++i)
		line[i].clear();
	for (int i=0, p=0, dir=-1; origin[i]; ++i)  {
		if (p==0 || p==n-1) dir=(dir==-1 ? 1 : -1);
		line[p] += origin[i];
		p += dir;
	}
	for (int i=0; i<n; ++i) {
		ans += line[i];
	}
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n); 
		scanf("%s", origin);
		solve(n);
		cout << ans << endl;
	}
}

