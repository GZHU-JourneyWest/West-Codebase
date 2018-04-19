// 1-based: scanf("%s", str+1);
int solve()
{
	int i = 0, mx = 1; str[0] = '*';
	while (str[i])
	{
		int p = i;
		while (str[i+1] == str[i]) ++i;
		int q = i;  // q之前不可能有更强的回文中心
		
		while (str[q-1]==str[p+1]) --q, ++p;
		mx = max(mx, q-p+1);
		
		++i;
	}
	return mx;
}
