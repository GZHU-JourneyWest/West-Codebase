#include <bits/stdc++.h>
using namespace std;

char buf[2048];
char cov[2048];

void build()
{
	for (int i=0, p=0; buf[i]; ++i) {
		if (isalpha(buf[i])) {
			cov[p++] = tolower(buf[i]);
		}
	}
}

int find()
{
	int ans = 1;
	for (int i=0; cov[i]; ++i) {
		int p = i, q = i;
		
		while (cov[q] == cov[q+1]) ++q;
		i = q;
		
		while (p>0 && cov[q+1] && cov[p-1] == cov[q+1]) ++q, --p;
		ans = max(ans, q-p+1);
	}
	return ans;
}

int main()
{
	while (scanf("%s", buf) == 1) {
		memset(cov, 0, sizeof(cov)); build();
		int len = strlen(buf);
		int rev = find();
		
		printf("%d\n", len-rev);
	}
}
