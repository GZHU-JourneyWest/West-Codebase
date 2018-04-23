// 根节点为1
int leaf[maxN];  // 记录叶子节点的索引
struct SegmentTreeNode{
	int l, r;
	LL val, vmx, vmn;
} node[maxN<<2];  // 四倍最大节点数量

// build(1, 1, n, arr);
// 使用arr数组提供的初值，以1为根节点，建立覆盖区间[1, n]的线段树
void build(int rt, int l, int r, LL *arr)
{
	node[rt].l = l, node[rt].r = r;
	if (l==r) {
		leaf[l] = rt;
		node[rt].val = node[rt].vmx = node[rt].vmn = arr[l];
	}
	else {
		int mid = (l+r)/2;
		build(rt<<1, l, mid, arr);
		build(rt<<1|1, mid+1, r, arr);
		node[rt].val = node[rt<<1].val + node[rt<<1|1].val;
		node[rt].vmx = max(node[rt<<1].vmx, node[rt<<1|1].vmx);
		node[rt].vmn = min(node[rt<<1].vmn, node[rt<<1|1].vmn);
	}
}

void pushup(int rt) {
	while (rt>>=1) {
		node[rt].val = node[rt<<1].val + node[rt<<1|1].val;
		node[rt].vmx = max(node[rt<<1].vmx, node[rt<<1|1].vmx);
		node[rt].vmn = min(node[rt<<1].vmn, node[rt<<1|1].vmn);
	}
}

// 将节点修改为val，rt必须是叶子节点
void modify_leaf(int rt, LL val) {
	node[rt].val = node[rt].vmx = node[rt].vmn = val; 
	pushup(rt); 
}

// 将节点值增加diff
void update(int rt, LL diff)
{
	node[rt].val += diff;
	node[rt].vmx = node[rt].vmn = node[rt].val; 
	pushup(rt);
}

// 查询区间元素的和
LL query(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) 
		return node[rt].val;
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query(rt<<1, l, r);
	else if(mid<l)
		return query(rt<<1|1, l, r);
	else
		return query(rt<<1, l, mid) + query(rt<<1|1, mid+1, r);
}

LL query_max(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) 
		return node[rt].vmx;
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query_max(rt<<1, l, r);
	else if(mid<l)
		return query_max(rt<<1|1, l, r);
	else
		return max(query_max(rt<<1, l, mid), query_max(rt<<1|1, mid+1, r));
}

LL query_min(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) 
		return node[rt].vmn;
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query_min(rt<<1, l, r);
	else if(mid<l)
		return query_min(rt<<1|1, l, r);
	else
		return min(query_min(rt<<1, l, mid), query_min(rt<<1|1, mid+1, r));
}