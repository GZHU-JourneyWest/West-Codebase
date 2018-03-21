#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int maxN = 1000100;

unsigned num[maxN];

void Create(unsigned res[],int n,unsigned int A, unsigned int B, unsigned int c){
    for(int i=0;i<n;i++){
        res[i]=A+B;
        A=((A<<2)+c)*i*29+B;
        B=(((A+B)<<3)+c)*17;
    }
}
 
unsigned kth(int bgn, int end, int k)
{
	unsigned privot = num[bgn];
	
	int i = bgn+1, j = end;
	while (true)
	{
		while (i<=end && num[i]>=privot) ++i;
		while (j>bgn && num[j]<privot) --j;
		if (i>=j) break;
		else swap(num[i], num[j]);
	}
	int left = j-bgn;
	if (left == k-1) return privot;
	else if (left > k-1) return kth(bgn+1, j, k); 
	else return kth(i, end, k-left-1);  
}

int main()
{	
	int t; scanf("%d", &t);
	while (t--)
	{
		int n, a, b, c, k;
		scanf("%d%d%d%d%d", &n, &a, &b, &c, &k);
		Create(num, n, a, b, c);
		printf("%u\n", kth(0, n-1, k));
	}
}
