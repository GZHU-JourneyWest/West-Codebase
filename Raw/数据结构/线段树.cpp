#define lson(x) ((x)<<1)
#define rson(x) ((x)<<1|1)
int leaf[maxN];  // 记录叶子节点的索引
struct SegmentTreeNode{
	int l, r;
	LL val, vmx, vmn;
} node[maxN<<2];  // 根节点为1，占据四倍序列长度空间 

// build(1, 1, n, arr)
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
		build(lson(rt), l, mid, arr);
		build(rson(rt), mid+1, r, arr);
		node[rt].val = node[lson(rt)].val + node[rson(rt)].val;
		node[rt].vmx = max(node[lson(rt)].vmx, node[rson(rt)].vmx);
		node[rt].vmn = min(node[lson(rt)].vmn, node[rson(rt)].vmn);
	}
}

void pushup(int rt) {
	while (rt>>=1) {
		node[rt].val = node[lson(rt)].val + node[rson(rt)].val;
		node[rt].vmx = max(node[lson(rt)].vmx, node[rson(rt)].vmx);
		node[rt].vmn = min(node[lson(rt)].vmn, node[rson(rt)].vmn);
	}
}

// modify(leaf[x], val)
// 将叶子x节点修改为val
void modify(int rt, LL val) {
	node[rt].val = node[rt].vmx = node[rt].vmn = val; 
	pushup(rt); 
}

// update(leaf[x], diff)
// 将叶子节点x值增加diff
void update(int rt, LL diff)
{
	node[rt].val += diff;
	node[rt].vmx = node[rt].vmn = node[rt].val; 
	pushup(rt);
}

// query(1, l, r)
// 自根节点向下，查询区间[l, r]和
LL query(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) 
		return node[rt].val;
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query(lson(rt), l, r);
	if (mid<l)
		return query(rson(rt), l, r);
	return query(lson(rt), l, mid) + query(rson(rt), mid+1, r);
}

// query_max(1, l, r)
// 自根节点向下，查询区间max{[l, r]}
LL query_max(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) 
		return node[rt].vmx;
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query_max(lson(rt), l, r);
	if (mid<l)
		return query_max(rson(rt), l, r);
	return max(query_max(lson(rt), l, mid), query_max(rson(rt), mid+1, r));
}

// query_min(1, l, r)
// 自根节点向下，查询区间min{[l, r]} 
LL query_min(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) 
		return node[rt].vmn;
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query_min(lson(rt), l, r);
	if (mid<l)
		return query_min(rson(rt), l, r);
	return min(query_min(lson(rt), l, mid), query_min(rson(rt), mid+1, r));
}