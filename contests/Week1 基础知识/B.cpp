#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct job
{
	LL id, cost, fine;
} j[1010];

bool cmp(const job &a, const job &b)
{
	LL fab = a.cost*a.fine + (a.cost+b.cost)*b.fine;
	LL fba = b.cost*b.fine + (a.cost+b.cost)*a.fine; 
	if (fab == fba) return a.id < b.id;
	else return fab < fba;
} 

int main()
{
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i=0; i<n; ++i) 
		{
			j[i].id = i+1;
			cin >> j[i].cost >> j[i].fine;
		}
		sort(j, j+n, cmp); 
		
		for (int i=0; i<n; ++i) {
			if (i) cout << ' ';
			cout << j[i].id;
		}
		cout << endl;
		if (t) cout << endl;
	}	
}
