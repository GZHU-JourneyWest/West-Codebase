// 1-based; 序列的初始值可以保存在∆(i)*i树状数组中
LL Di[maxN], Dii[maxN];  // ∆(i), ∆(i)*i

void add(LL *bit, int x, int val) {
	for (int i=x; i<maxN; i+=lowbit(i)) {
		bit[i] += val;
	}
}

LL sum(LL *bit, int x) {
	LL rslt = 0;
	for (int i=x; i; i-=lowbit(i)) {
		rslt += bit[i];
	}
	return rslt;
}

// 将[a, b]区间中的元素增加val
void add(int a, int b, LL val) {
	add(Di, a, val);
	add(Di, b+1, -val);
	add(Dii, a, -a*val);
	add(Dii, b+1, (b+1)*val);
}

// 求前缀和[1, x]
LL sum(int x) {
	return sum(Di, x)*(x+1) + sum(Dii, x);
}

// 区间和[a, b]
LL get(int a, int b) {
	return sum(b) - sum(a-1);
}
