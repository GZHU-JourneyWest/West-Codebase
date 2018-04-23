// cell[x][y]增加v
void add(int x, int y, int v)
{
	for (int i = x; i<maxN; i+=lowbit(i))
		for (int j = y; j<maxN; j+=lowbit(j))
			cell[i][j] += v;
}

// (1, 1)至(x, y)中所有单元格的数值和
int get(int x, int y)
{
	int rslt = 0;
	for (int i = x; i; i-=lowbit(i))
		for (int j = y; j; j-=lowbit(j))
			rslt += cell[i][j];
	return rslt;
}
