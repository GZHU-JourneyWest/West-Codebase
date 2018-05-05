vector<int> g[maxN];  // g[x]：与x点相连的右侧的点
int from[maxN], tot;  // from[x]: 与右侧点x匹配的左侧的点，tot：最大匹配数
bool use[maxN];

bool match(int x)  // x：待匹配的一个左侧的点
{
	for (unsigned i=0; i<g[x].size(); ++i) if (!use[g[x][i]])
	{
		use[g[x][i]] = true;
		if (from[g[x][i]] == -1 || match(from[g[x][i]])) {
			from[g[x][i]] = x; return true;
		}
	}
	return false;
}

int hungary(int n)  // n：左侧点的个数
{
	memset(from, -1, sizeof(from)); tot = 0;
	for (int i=1; i<=n; ++i) {
		memset(use, 0, sizeof(use));
		if (match(i)) ++tot;
	}
	return tot;
}