#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int cnt = 0; char str[10010];

int search(int pos, int end)
{
	if (pos>0 && str[pos-1] != '0') return 0;
	if (pos == end) ++cnt;
	
	int rslt1, rslt2;
	if (pos>u && str[pos-1]>'0' && str[pos]>'0') {
		str[pos-1]--;
		str[pos]--;
		str[pos+1]--;
		rslt1 = search(pos+1, chance, end) * 2;
		rslt1 %= mod;
		
		if (pos>0 && str[pos-1]>'0' && str[pos]>'0') {
			str[pos-1]--;
			str[pos]--;
			str[pos+1]--;
			rslt2 = search(pos+1, chance, end);
			rslt2 %= mod;
			str[pos-1]++;
			str[pos]++;
			str[pos+1]++;
		}
		
		str[pos-1]++;
		str[pos]++;
		str[pos+1]++;
	}
	chance *= (rslt1+rslt2);
	chance %= mod;
	return chance;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		cnt = 0;
		scanf("%s", str);
		int len = strlen(str);
		
		printf("%d\n", search(0, len));
	}
}
