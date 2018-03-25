#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL INF = 0x3F3F3F3F3F3F3F3F;
const int maxN = 1010;

pair<LL, LL> star[maxN];
LL dis[maxN][maxN], fact[maxN];
vector<LL> que;

LL distance(int a, int b) 
{
	LL dx = star[a].first-star[b].first;
	LL dy = star[a].second-star[b].second;
	return dx*dx+dy*dy;
}

LL factorial(int n)
{
	if (fact[n]) return fact[n];
	
	LL ans = 1;
	for (int i=1; i<=n; ++i)
		ans *= i;
	return ans;
}

LL calculate(int n)
{
	if (n<2) return 0;
	return factorial(n) / factorial(n-2);
}

int main()
{
	fact[0] = 1;
	
	int t; scanf("%d", &t);
	while (t--) 
	{
		int n; scanf("%d", &n);
		
		for (int i=0; i<n; ++i) {
			scanf("%lld%lld", &star[i].first, &star[i].second);
		}
		
		if (n==1 || n==2) {
			printf("WA\n");
			continue;
		}
		
		for (int i=0; i<n; ++i) {
			dis[i][i] = INF;
			for (int j=i+1; j<n; ++j) {
				dis[i][j] = distance(i, j);
				dis[j][i] = dis[i][j];
			}
		}
		
		LL ans = 0;
		for (int i=0; i<n; ++i) {
			que.clear();
			for (int j=0; j<n; ++j) {
				if (i==j) continue;
				que.push_back(dis[i][j]);
			}
			sort(que.begin(), que.end());
			
			int cnt = 1; LL prev = que[0];
			for (int i=1; i<n; ++i) {
				if (que[i] == prev) ++cnt;
				else {
					ans += calculate(cnt);
					cnt = 1, prev = que[i];
				}
			}
			ans += calculate(cnt);
		}
		
		if (!ans) 
			printf("WA\n");
		else 
			printf("%lld\n", ans);
	}
}
