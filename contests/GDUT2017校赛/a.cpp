#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL dfs(int m) {
	if (m == 0) return 1;
	if (m == 1) return 1;
	if (m == 2) return 2;
	
	LL ans = 0;
	for (int i=m; i>=1; --i) {
		ans += dfs(m-i);
	}
	return ans;
}

int main()
{
	#ifdef LOCAL
	freopen("out.txt", "w", stdout);
	#endif
	
	for (int i=1; i<31; ++i) {
		cout << dfs(i) << endl;
	}
}
