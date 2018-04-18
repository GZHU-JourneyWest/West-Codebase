vector<LL> line_mod_equation(LL a, LL b, LL n)
{
	LL x, y;
	LL d = gcd(a, n, x, y);

	vector<LL> ans;
	if (b%d == 0) {
		x %= n; x += n; x %= n;
		ans.push_back(x*(b/d)%(n/d));
		for (LL i=1; i<d; ++i)
			ans.push_back((ans[0]+i*(n/d))%n);
	}
	return ans;
}
