int pre[maxN]; fill(pre, pre+maxN, 0);
char s[maxN], p[maxN]; scanf("%s%s", s+1, p+1);

for (int i = 2, j = 0; p[i]; ++i)  // 取得pre数组
{
	while (j > 0 && p[i] != p[j+1]) j = pre[j];
	if (p[i] == p[j+1]) ++j;
	pre[i] = j;
}

for (int i = 1, j = 0; s[i]; ++i)  // 开始匹配
{
	while (j > 0 && s[i] != p[j+1]) j = pre[j];
	if (s[i] == p[j+1]) ++j;
	if (!p[j+1]) ++cnt; // 匹配成功
}
