#include <bits/stdc++.h>
using namespace std;

char buf[55];

int main()
{
	int n; scanf("%d", &n); fgets(buf, sizeof(buf), stdin);
	while (n--) {
		fgets(buf, sizeof(buf), stdin);
		
		bool ok = true;
		bool hasOther = false;
		for (int i=0; ok && buf[i]!='\n'; ++i)
		{
			if (isdigit(buf[i])) {
				if (!hasOther) ok = false;
 			}
			else if (isalpha(buf[i]) || buf[i] == '_') 
				hasOther = true;
			else ok = false;
		}
		
		printf(ok ? "yes\n" : "no\n");
	}
} 
