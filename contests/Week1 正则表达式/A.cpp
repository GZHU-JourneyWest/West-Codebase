#include <bits/stdc++.h>
using namespace std;

const char vovels[] = "aeiou";
const char deny[]   = "not ";

char buf[128];

int main()
{
	while (fgets(buf, sizeof(buf), stdin) != nullptr)
	{
		if (strcmp(buf, "end\n") == 0) break;
	
		bool flag = true;
		int totv = 0;
		int vcnt = 0, ccnt = 0; char last = '.';
		for (int i=0; buf[i]; ++i) {
			if (buf[i] == '\n') {
				buf[i] = 0; break;
			}
			
			if (strchr(vovels, buf[i]) != nullptr) ++totv, ++vcnt, ccnt = 0; 
			else ++ccnt, vcnt = 0; 
			
			if (ccnt > 2 || vcnt > 2) flag = false;
			if (last == buf[i] && !(last == 'e' || last == 'o')) flag = false;
			
			last = buf[i];
		}
		if (totv == 0) flag = false;
		
		printf("<%s> is %sacceptable.\n", buf, (flag ? "" : deny));
	}
}
