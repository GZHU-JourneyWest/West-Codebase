#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int maxN = 1000100;

unsigned num[2][maxN];

// O(t * n) 常数太大
void radixsort(int n) 
{
    for(int t = 0; t < 32; ++t)
    {
        int p = 0;
        int pos = t&1;
        unsigned bit = 1U<<t;
		for (int i=0; i<n; ++i) {
        	if (num[pos][i]&bit) 
        		num[!pos][p++] = num[pos][i];
		}
		for (int i=0; i<n; ++i) {
        	if (!(num[pos][i]&bit)) 
        		num[!pos][p++] = num[pos][i];
		}
    }
}

string binary(unsigned x)
{
	string rslt;
	for (int i=0; i<32; ++i) {
		rslt += ((x&(1U<<i)) ? "1" : "0");
	}
	return rslt;
}

void Create(unsigned res[],int n,unsigned int A, unsigned int B, unsigned int c){
    for(int i=0;i<n;i++){
        res[i]=A+B;
        A=((A<<2)+c)*i*29+B;
        B=(((A+B)<<3)+c)*17;
    }
}

int main()
{
	#ifdef LOCAL
	freopen("out.txt", "w", stdout);
	#endif
	
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, a, b, c, k;
		scanf("%d%d%d%d%d", &n, &a, &b, &c, &k);
		Create(num[0], n, a, b, c);
		radixsort(n);
		
		printf("%u\n", num[0][k-1]);
	}
}
