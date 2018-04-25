Point p[maxN];  // 点集
int s[maxN];    // 临时变量

bool cmpx(int i, int j) {
	return sgn(p[i].x-p[j].x)<0;
}

bool cmpy(int i, int j) {
	return sgn(p[i].y-p[j].y)<0;
}

// 最近点对分治步骤
double min_dist(Point p[], int s[], int l, int r)
{
	double ans = 1e100;
	if (r-l<20) {
		for (int q=l; q<r; ++q) for (int w=q+1; w<r; ++w) {
			ans = min(ans, (p[s[q]]-p[s[w]]).norm());
		}
		return ans;
	}

	int tl, tr, m=(l+r)/2;
	ans = min(min_dist(p, s, l, m), min_dist(p, s, m, r));
	for (tl=l; p[s[tl]].x<p[s[m]].x-ans; ++tl);
	for (tr=r-1; p[s[tr]].x>p[s[m]].x+ans; --tr);
	sort(s+tl, s+tr, cmpy);
	for (int q=tl; q<tr; ++q) {
		for (int w=q+1; w<min(tr, q+6); ++w) {
			ans = min(ans, (p[s[q]]-p[s[w]]).norm());
		}
	}
	sort(s+tl, s+tr, cmpx);
	return ans;
}

// 最近点对 - 求解n个点中最近两点的距离
// p - 点集, n - 点数
// s - 临时变量，算法执行后得到x坐标非降序排列的点编号
double min_dist(Point p[], int s[], int n)
{
	iota(s, s+n, 0);
	sort(s, s+n, cmpx);  // 以x坐标非降序编号点
	return min_dist(p, s, 0, n);
}
