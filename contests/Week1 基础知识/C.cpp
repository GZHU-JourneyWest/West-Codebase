#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// ×ø±êÓ³Éä·´Ïò 
// L47 -> L48

const int INF = 0x3F3F3F3F;

struct ant
{
	int id; LL pos, dir;
	bool operator <(const ant &b) const {
		return pos < b.pos;
	}
} a[1010000];

int seq[1010000];

bool cmp(const ant &a, const ant &b) {
	return a.pos < b.pos;
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int t; cin >> t;
	for (int kase = 1; kase <= t; ++kase)
	{
		if (kase != 1) cout << endl;
		cout << "Case #" << kase << ":" << endl;
		
		int L, T, n; cin >> L >> T >> n;
		
		for (int i=1; i<=n; ++i) {
			char ch; cin >> a[i].pos >> ch;

			a[i].id  = i;
			a[i].dir = (ch == 'R' ? 1 : -1); 
		}
		sort(a+1, a+1+n);
		for (int i=1; i<=n; ++i) {
			// seq[i] = a[i].id;
			seq[a[i].id] = i;
		}
		
		a[0].pos = -INF, a[n+1].pos = INF;
		for (int i=1; i<=n; ++i) {
			a[i].pos += a[i].dir*T;
		}
		sort(a+1, a+1+n);
		
		for (int i=1; i<=n; ++i) {
			int tar = seq[i];
			
			if (a[tar].pos < 0 || a[tar].pos > L) {
				cout << "Fell off" << endl; continue;
			}
			else cout << a[tar].pos << ' ';
			
			bool sp = (a[tar-1].pos == a[tar].pos || a[tar].pos == a[tar+1].pos);
			if (sp) cout << "Turning" << endl;
			else cout << (a[tar].dir==1 ? "R" : "L") << endl;
		}
	}
	
	cout << endl;
}
