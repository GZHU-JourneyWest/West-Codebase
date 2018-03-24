#include <bits/stdc++.h>
using namespace std;

int n, m;
char buf[100][100];

void output(int dir) 
{
	if (dir == 0) {
		printf("%d %d\n", n, m);
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=m; ++j) 
				putchar(buf[i][j]);
			putchar('\n');
		}
	}
	if (dir == 1) {
		printf("%d %d\n", m, n);
		for (int i=m; i>=1; --i) {
			for (int j=1; j<=n; ++j) {
				if (buf[j][i] == '-') putchar('|');
				else if (buf[j][i] == '|') putchar('-');
				else putchar(buf[j][i]);
			}
			putchar('\n');
		}
	}
	if (dir == 2) {
		printf("%d %d\n", n, m);
		for (int i=n; i>=1; --i) {
			for (int j=m; j>=1; --j) {
				putchar(buf[i][j]);
			}
			putchar('\n');
		}
	}
	if (dir == 3) {
		printf("%d %d\n", m, n);
		for (int i=1; i<=m; ++i) {
			for (int j=n; j>=1; --j) {
				if (buf[j][i] == '|') putchar('-');
				else if (buf[j][i] == '-') putchar('|');
				else putchar(buf[j][i]);
			}
			putchar('\n');
		}
	}
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	#endif
	
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);	
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=m; ++j) 
				scanf(" %c", &buf[i][j]);
		
		int dir = 0;
		string s; cin >> s;
		for (char ch : s) {
			dir += (ch == 'L' ? 1 : -1);
		}
		dir = (dir%4+4) % 4;
		output(dir);
		putchar('\n');
	}
}
