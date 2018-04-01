#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL goal(const string &s)
{
	LL tot = 0, cnt = 0;
	for (unsigned i=0; i<s.size(); ++i) {
		if (s[i] == 's') ++cnt;
		else tot += cnt;
	}
	return tot;
}

bool cmp(const string &a, const string &b)
{
	string ab = a+b;
	string ba = b+a;
	return goal(ab) > goal(ba);	
}

string str[101000];


int main()
{
	int n; cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> str[i];
	}
	sort(str, str+n, cmp);
	
	string opt;
	for (int i=0; i<n; ++i) {
		opt += str[i];
	}
	cout << goal(opt) << endl;
}
