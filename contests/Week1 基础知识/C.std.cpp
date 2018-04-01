#include <bits/stdc++.h>
using namespace std;

const int maxN = 10000+5;
const char dirName[][10] = {"L", "Turning", "R"}; 

struct ant 
{
	int id;
	int p;
	int d;
	
	bool operator <(const ant &a) const {
		return p < a.p;	
	}
} before[maxN], after[maxN];

int order[maxN];

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	
	int k; cin >> k;
	for (int kase = 1; kase <= k; ++kase)
	{
		int L, T, n; cin >> L >> T >> n;
		
		cout << "Case #" << kase << ":" << endl;
		
		for (int i=0; i<n; ++i) {
			int p, d;
			char ch;
			
			cin >> p >> ch;
			d = (ch=='L' ? -1 : 1);
			before[i] = {i, p, d};
			after[i] = {0, p+T*d, d};
		}
		
		sort(before, before+n);
		for (int i=0; i<n; ++i) {
			order[before[i].id] = i;
		}
		
		sort(after, after+n);
		for (int i=0; i<n-1; ++i) {
			if (after[i].p == after[i+1].p) 
				after[i].d = after[i+1].d = 0;
		}
		
		for (int i=0; i<n; ++i) {
			int a = order[i];
			if (after[a].p < 0 || after[a].p > L) cout << "Fell off" << endl;
			else cout << after[a].p << ' ' << dirName[after[a].d+1] << endl;
		} 
		cout << endl;
	}
}
