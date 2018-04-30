vector<int> num;  // 维护num序列的最值
int preLog2[maxN];
int st[maxN][32];

// 建立preLog2和st
void init()
{
	int n=num.size();
	
	preLog2[1] = 0;
	for (int i=2; i<=n; ++i) {
		preLog2[i] = preLog2[i-1];
		if (1<<(preLog2[i]+1) == i) {
			++preLog2[i];
		}
	}
	for (int i=n-1; i>=0; --i) {
		st[i][0] = num[i];
		for (int j=1; i+(1<<j)-1<n; ++j) {
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
}

// 查询区间[x, y]上的最值
int query(int x, int y)
{
	int k = preLog2[y-x+1];
	return min(st[x][k], st[y-(1<<k)+1][k]);
}
