#include <bits/stdc++.h>
using namespace std;

char buf[128];

int main()
{
	while (fgets(buf, sizeof(buf), stdin) != nullptr) 
	{
		bool flag = true;
		int num[4] {-1, -1, -1, -1}, cur = 0;
		for (int i=0; flag && buf[i] != '\n'; ++i) {
			if (isdigit(buf[i])) {
				if (num[cur] == -1) num[cur] = 0;
				num[cur] = num[cur]*10 + buf[i]-'0';
				if (num[cur] > 255) flag = false;
			}
			else if (buf[i] == '.') {
				++cur;
				if (cur > 3) flag = false;
			}
			else flag = false;
		}
		for (int &p : num) if (p == -1) flag = false;
		if (cur != 3) flag = false;
		
		puts(flag ? "YES" : "NO");
	}
}
