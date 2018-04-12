#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt", "w", stdout);
	
	int n = 35, x = 3777, y = 3778;
	cout << n << ' ' << x << ' ' << y << ' ' << endl;
	
	for (int i=0; i<n; ++i) {
		cout << rand()%10001 << ' ' << rand()%10000+1 << endl;
	}
}
