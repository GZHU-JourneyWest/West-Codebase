int cell[maxN];  // 有效索引从1开始

#define lowbit(x) (x)&(-(x))
void add(int x, int v) {
	for (int i = x; i < maxN; i += lowbit(i))
		cell[i] += v;
} 

int get(int x) {
	int sum = 0;
	for (int i = x; i; i -= lowbit(i))
		sum += cell[i];
	return sum;
}
