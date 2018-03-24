#include <bits/stdc++.h>
using namespace std;

char reg[250], buf[250];

int main() 
{
	int n; scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	{
		scanf("%s%s", buf, reg);
		regex regx(reg);
		printf("Case %d: %s\n", i, (regex_match(buf, regx) ? "Yes" : "No")); 
	}
}
