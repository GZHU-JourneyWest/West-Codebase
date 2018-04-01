#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	
	char ch = 'a'; int cnt = 0;
	while (n--) {
		cout << ch;
		++cnt;
		if (cnt == 2) {
			cnt = 0; 
			ch = (ch == 'a' ? 'b' : 'a');
		}
	} 
	cout << endl;
} 
