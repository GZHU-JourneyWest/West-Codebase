#include <bits/stdc++.h>
using namespace std;

// 与标准正则语法的区别是
// “.*”的中的“.”只能代表某一种的字符，而不是可以转化成任意字符 

const string any = 
	"(a*|b*|c*|d*|e*|f*|g*|h*|i*|j*|k*|l*|m*|n*|o*|p*|q*|r*|s*|t*|u*|v*|w*|x*|y*|z*"
	"|A*|B*|C*|D*|E*|F*|G*|H*|I*|J*|K*|L*|M*|N*|O*|P*|Q*|R*|S*|T*|U*|V*|W*|X*|Y*|Z*)"
;

string tar, pat;

int main()
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); 
	
	int t; cin >> t;
	while (t--) {
		cin >> tar >> pat;
		for (int pos; pos = pat.find(".*"), ~pos; ) pat.replace(pos, 2, any);
	
		regex reg(pat);
		cout << (regex_match(tar, reg) ? "yes" : "no") << endl;	
	}
} 
