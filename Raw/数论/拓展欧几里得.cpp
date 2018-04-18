LL gcd(LL a, LL b, LL &x, LL &y)
{
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	else {
		LL r = gcd(b, a%b, y, x);
		y -= (a/b)*x;
		return r;
	}
}
