int pre[maxN]; 
char s[maxN], p[maxN];  // 文本串、模板串 

void prepare() {
	fill(pre, pre+maxN, -1);
	for (int i=1, j=-1; p[i]; ++i)  
	{
		while (j>=0 && p[i] != p[j+1]) j = pre[j];
		if (p[i] == p[j+1]) ++j;
		pre[i] = j;
	}
}

void kmp(vector<int> &match)
{
	match.clear(); prepare();
	for (int i=0, j=-1; s[i]; ++i) {
		while (j>=0 && s[i] != p[j+1]) j = pre[j];
		if (s[i] == p[j+1]) ++j;
		if (!p[j+1]) {  // 匹配成功 
			match.push_back(i-j);
			j = pre[j];
		}
	}
}
