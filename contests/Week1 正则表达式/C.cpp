#include <bits/stdc++.h>
using namespace std;

char buf[1024];

int main()
{
	int n; scanf("%d", &n); fgets(buf, sizeof(buf), stdin);
	for (int i=1; i<=n; ++i)
	{
		fgets(buf, sizeof(buf), stdin);
		
		char *head = strstr(buf, "://");
		char *tail = strpbrk(head+3, ":/");
		if (tail) *tail = 0;
		printf("Case #%d: %s\n", i, head+3);
	}
}
