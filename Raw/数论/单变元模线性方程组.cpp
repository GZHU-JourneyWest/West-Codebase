vector<LL> line_mod_equation(LL a, LL b, LL n)
{
	LL x, y, g; exgcd(a, n, g, x, y);

	vector<LL> ans;
	if (b%g == 0) {
		x %= n; x += n; x %= n;
		ans.push_back(x*(b/g)%(n/g));
		for (LL i=1; i<g; ++i)
			ans.push_back((ans[0]+i*(n/g))%n);
	}
	return ans;
}
