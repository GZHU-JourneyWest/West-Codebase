const int maxN = 550;
const int maxM = 550;

// 注意到模乘的效率比向上转型做乘法取模再向下转型低
int mod_mult(int a, int b)
{
	int ans = 0, base = a % mod;
	if (b<0) b += mod;
	while (b)
	{
		if (b&1) ans += base; ans %= mod;
		base <<= 1; base %= mod;
		b >>= 1;
	}
	return ans;
}

// 基本矩阵运算朴素实现
// 注意到数组类型long long有可能导致Stack Overflow
struct Matrix
{
	int n, m;
	int v[maxN][maxM];
	
	void clear()
	{
		n = m = 0;
		memset(v, 0, sizeof(v));
	}
	
	Matrix operator +(const Matrix &b) const 
	{
		Matrix ans; ans.n = n, ans.m = m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ans.v[i][j] = (v[i][j] + b.v[i][j]);
		return ans;
	}
	
	Matrix operator -(const Matrix &b) const 
	{
		Matrix ans; ans.n = n, ans.m = m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ans.v[i][j] = (v[i][j] - b.v[i][j]);
		return ans;
	}
	
	Matrix operator *(const Matrix &b) const
	{
		Matrix ans; ans.clear(); ans.n = n, ans.m = b.m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < b.m; ++j)
			{
				for (int k = 0; k < m; ++k)
				{
					ans.v[i][j] += v[i][k] * b.v[k][j];
				}
			}
		return ans;
	}
};
