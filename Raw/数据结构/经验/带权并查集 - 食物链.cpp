// POJ-1182

int n;
int fa[50500], rk[50500]; // rk[x] = r(x->find(x)): 0-同类 1-捕食者 2-被捕食者

void init() {
	for (int i = 0; i <= n; ++i) fa[i] = i, rk[i] = 0;
}

// 寻找x的先祖节点，并维护rk
int find(int x)
{
	if (fa[x] == x) return x;
	int old = fa[x]; fa[x] = find(fa[x]);
	rk[x] = (rk[x] + rk[old]) % 3;
	return fa[x];
}

// 利用rk信息检查“一句话”是否合理
bool check(int a, int b, int r)
{
	if (max(a, b) > n) return false;
	if (a==b && r!=0) return false;
	if (find(a) != find(b)) return true;
	return rk[a] == (r+rk[b])%3;
}

// 合并集合，并维护rk
void merge(int a, int b, int r) {
	int ra = find(a), rb = find(b);
	if (ra == rb) return;
	fa[ra] = rb; rk[ra] = (r+rk[b]-rk[a]+3)%3;
}

int main()
{
	int k; scanf("%d%d", &n, &k);
	{
		init(); int ans = 0;
		while (k--) {
			int r, x, y; scanf("%d%d%d", &r, &x, &y);
			if (!check(x, y, r-1)) ++ans;
			else merge(x, y, r-1);
		}
		printf("%d\n", ans);
	}
}