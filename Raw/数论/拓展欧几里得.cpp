void exgcd(LL a, LL b, LL& g, LL &x, LL &y)
{
	if (!b) g=a, x=1, y=0;
	else exgcd(b, a%b, g, y, x), y-=a/b*x;
}
