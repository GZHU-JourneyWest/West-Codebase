#define lson(x) ((x)<<1)
#define rson(x) ((x)<<1|1)
struct SegmentTreeNode{
	int l, r;
	LL val, vmx, vmn;
	LL lazy;  // 延迟标记，表示管辖区域内每个单独节点的增量
	LL force;    // 覆盖标记，表示管辖区域内每个节点被修改后的值，注意修改为0的情况
} node[maxN<<2];  // 根节点为1，四倍空间初始化
bool covered[maxN<<2];  // 节点管辖区域是否被覆盖

// build(1, 1, n, arr)
// 使用arr数组提供的初值，以1为根节点，建立覆盖区间[1, n]的线段树
void build(int rt, int l, int r, LL *arr)
{
	node[rt].l = l, node[rt].r = r;
	node[rt].lazy = node[rt].force = 0;
	if (l==r) {
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

// 下传延迟标记或覆盖标记 
void pushdown(int rt)
{
	if (covered[rt]) {
		node[rt].val = node[rt].force*(node[rt].r-node[rt].l+1);
		node[rt].vmx = node[rt].vmn = node[rt].force;
		covered[lson(rt)] = covered[rson(rt)] = true;
		node[lson(rt)].lazy  = node[rson(rt)].lazy  = 0;
		node[lson(rt)].force = node[rson(rt)].force = node[rt].force;
		covered[rt] = false;
	}
	if (node[rt].lazy) {
		node[rt].val += node[rt].lazy*(node[rt].r-node[rt].l+1);
		node[rt].vmx += node[rt].lazy;
		node[rt].vmn += node[rt].lazy;
		node[lson(rt)].lazy += node[rt].lazy;
		node[rson(rt)].lazy += node[rt].lazy;
		node[rt].lazy = 0;
	}
}

// query(1, l, r)
// 自根节点向下，查询区间[l, r]和
LL query(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) {
		if (covered[rt]) return (node[rt].force+node[rt].lazy)*(node[rt].r-node[rt].l+1);
		return node[rt].val + node[rt].lazy*(node[rt].r-node[rt].l+1);
	}
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query(lson(rt), l, r);
	if (mid<l)
		return query(rson(rt), l, r);
	return query(lson(rt), l, mid) + query(rson(rt), mid+1, r);
}

LL query_max(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) {
		if (covered[rt]) return node[rt].force + node[rt].lazy; 
		return node[rt].vmx + node[rt].lazy;
	}
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query_max(lson(rt), l, r);
	if(mid<l)
		return query_max(rson(rt), l, r);
	return max(query_max(lson(rt), l, mid), query_max(rson(rt), mid+1, r));
}

LL query_min(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) {
		if (covered[rt]) return node[rt].force + node[rt].lazy;
		return node[rt].vmn + node[rt].lazy;	
	}
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query_min(lson(rt), l, r);
	if (mid<l)
		return query_min(rson(rt), l, r);
	return min(query_min(lson(rt), l, mid), query_min(rson(rt), mid+1, r));
}

// update(1, l, r, diff)
// 自根节点向下，将[l, r]区间内的元素增加diff
void update(int rt, int l, int r, int diff)
{
	if (l<=node[rt].l&&node[rt].r<=r) {
		node[rt].lazy += diff;
		return;
	}
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid) {
		update(lson(rt), l, r, diff);
	} 
	else if (mid<l) {
		update(rson(rt), l, r, diff);
	}
	else {
		update(lson(rt), l, r, diff);
		update(rson(rt), l, r, diff);
	}
	node[rt].val = query(lson(rt), node[rt].l, mid) + query(rson(rt), mid+1, node[rt].r);
	node[rt].vmx = max(query_max(lson(rt), node[rt].l, mid), query_max(rson(rt), mid+1, node[rt].r)); 
	node[rt].vmn = min(query_min(lson(rt), node[rt].l, mid), query_min(rson(rt), mid+1, node[rt].r)); 
}

// modify(1, l, r, val)
// 自根节点向下，将[l, r]区间的元素修改为val 
void modify(int rt, int l, int r, int val)
{
	if (l<=node[rt].l&&node[rt].r<=r) {
		node[rt].lazy = 0; node[rt].force = val;
		covered[rt] = true;
		return;
	}
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid) {
		modify(lson(rt), l, r, val);
	} 
	else if (mid<l) {
		modify(rson(rt), l, r, val);
	}
	else {
		modify(lson(rt), l, r, val);
		modify(rson(rt), l, r, val);
	}
	node[rt].val = query(lson(rt), node[rt].l, mid) + query(rson(rt), mid+1, node[rt].r);
	node[rt].vmx = max(query_max(lson(rt), node[rt].l, mid), query_max(rson(rt), mid+1, node[rt].r)); 
	node[rt].vmn = min(query_min(lson(rt), node[rt].l, mid), query_min(rson(rt), mid+1, node[rt].r)); 
}
