struct LeftTree
{
	const static int MXN = 100100;
	int tot = 0;
	int l[MXN], r[MXN], v[MXN], d[MXN];

	// 初始化值为x的元素
	int init(int x)
	{
		tot++;
		v[tot] = x;
		l[tot] = r[tot] = d[tot] = 0;
		return tot;
	}

	// 合并堆顶编号为x, y的堆
	int merge(int x, int y)
	{
		if (!x) return y;
		if (!y) return x;
		if (v[x] < v[y])
			swap(x, y);
		r[x] = merge(r[x], y);
		if (d[l[x]] < d[r[x]])
			swap(l[x], r[x]);
		d[x] = d[r[x]] + 1;
		return x;
	}

	// 向堆顶编号为x的堆中插入值为v的元素
	int insert(int x, int v)
	{
		return merge(x, init(v));
	}

	// 取编号为x的堆的堆顶元素
	int top(int x)
	{
		return v[x];
	}

	// 弹出编号为x的堆的堆顶元素，返回新堆顶的编号
	int pop(int x)
	{
		return merge(l[x], r[x]);
	}
};
