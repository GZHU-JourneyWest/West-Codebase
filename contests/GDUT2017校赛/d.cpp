#include <bits/stdc++.h>
using namespace std;

const int maxN = 2000;

char str[maxN];
int dp[maxN][maxN];

void lps(int n)
{
	memset(dp, 0, sizeof(dp));
	for (int i=0; i<maxN; ++i) dp[i][i] = 1;
	
	for (int s=1; s<=n-1; ++s) {
		for (int i=0; i+s<n; ++i) {
			int j=i+s;
			if (str[i] == str[j]) dp[i][j] = dp[i+1][j-1] + 2;
			else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
		}
	}
}

void deal()
{
	for (int i=0; str[i]; ++i) {
		if (isalpha(str[i])) 
			str[i] = tolower(str[i]); 
	}
}

int main()
{
	while (scanf("%s", str) == 1) {
		int len = strlen(str);
		deal(); lps(len);
		printf("%d\n", len-dp[0][len-1]);
	}
} 
