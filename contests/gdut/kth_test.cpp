#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// 递归次数测试
// 递归次数超过40000就有风险了

int n;
LL res[10000500];

void Create(long long res[], int n, unsigned int A, unsigned int B, unsigned int c){
    for(int i=0;i<n;i++) {
        res[i]=A+B;
        A=((A<<2)+c)*i*29+B;
        B=(((A+B)<<3)+c)*17;
    }
}

void watchdog(bool renew = false)
{
	static int kase = 0;
	static long long cnt = 0;
	if (renew) {
		cout << ++kase << " Recursion count= " << cnt << endl << flush;
		cnt = 0;
	}
	if (cnt > 42333) {
		cout << "Red Alert: " << cnt << endl << flush;
	} 
	++cnt;
}
 
LL kth(LL l, LL r, LL k)
{
	watchdog();
	
	if(l==r)
	{
		if(l==k) return res[k];
		else {
			if(l>k) return kth(0,l-1,k);
			else return kth(l+1,n-1,k);
		}
	}
	else
	{
		for(;r>l;r--)
		{
			if(res[r]>=res[l]) {
				swap(res[r],res[l]);
				break;
			}
		}
		
		for(;l<r;l++)
		{
			if(res[l]<res[r]) {
				swap(res[l],res[r]);
				break; 
			}
		}
		return kth(l,r,k);
	}
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int T; scanf("%d", &T); 
	while (T--) {
		int a, b, c, k; scanf("%d%d%d%d%d", &n, &a, &b, &c, &k);
		Create(res, n, a, b, c);
		
		printf("%lld\n", kth(0,n-1,k-1));
		watchdog(true);
	}
}

