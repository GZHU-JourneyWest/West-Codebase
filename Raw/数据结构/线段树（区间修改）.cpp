// 根节点为1
struct SegmentTreeNode{
	int l, r;
	LL val, vmx, vmn;
	LL lazy;  // 延迟标记，表示覆盖区域内每个单独节点的增量
} node[maxN<<2];  // 四倍空间初始化

// build(1, 1, n, arr)
// 使用arr数组提供的初值，以1为根节点，建立覆盖区间[1, n]的线段树
void build(int rt, int l, int r, LL *arr)
{
	node[rt].l = l, node[rt].r = r;
	node[rt].lazy = 0;
	if (l==r) {
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

// 下传延迟标记
void pushdown(int rt)
{
	if (node[rt].lazy) {
		node[rt].val += node[rt].lazy*(node[rt].r-node[rt].l+1);
		node[rt].vmx += node[rt].lazy;
		node[rt].vmn += node[rt].lazy;
		node[rt<<1].lazy += node[rt].lazy;
		node[rt<<1|1].lazy += node[rt].lazy;
	}
	node[rt].lazy = 0;
}

// 将[l, r]区间内的元素增加diff
void update(int rt, int l, int r, int diff)
{
	if (l<=node[rt].l&&node[rt].r<=r) {
		node[rt].lazy += diff;
		return;
	}
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid) {
		update(rt<<1, l, r, diff);
	} 
	else if (mid<l) {
		update(rt<<1|1, l, r, diff);
	}
	else {
		update(rt<<1, l, r, diff);
		update(rt<<1|1, l, r, diff);
	}
	node[rt].val = query(rt<<1, node[rt].l, mid) + query(rt<<1|1, mid+1, node[rt].r);
	node[rt].vmx = max(query_max(rt<<1, node[rt].l, mid), query_max(rt<<1|1, mid+1, node[rt].r)); 
	node[rt].vmn = min(query_min(rt<<1, node[rt].l, mid), query_min(rt<<1|1, mid+1, node[rt].r)); 
}

// 查询区间[l, r]内节点的权值和
LL query(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r)
		return node[rt].val + node[rt].lazy*(node[rt].r-node[rt].l+1);
	pushdown(rt);
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
		return node[rt].vmx + node[rt].lazy;
	pushdown(rt);
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
		return node[rt].vmn + node[rt].lazy;
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query_min(rt<<1, l, r);
	else if(mid<l)
		return query_min(rt<<1|1, l, r);
	else
		return min(query_min(rt<<1, l, mid), query_min(rt<<1|1, mid+1, r));
}