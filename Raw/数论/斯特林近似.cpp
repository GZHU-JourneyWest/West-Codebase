/** 
 * 斯特林公式求n!的长度
 * 
 * n != 0, 1时：
 * res = (long long)((log10(sqrt(4.0*acos(0.0)*n)) + n*(log10(n)-log10(exp(1.0)))) + 1)
 * 特殊处理 n=1, 0时的情况
**/

LL Stirling(int n) {
	if (n==0 || n==1) return 1;
	return LL(log10(sqrt(4.0*acos(0.0)*n)) + n*(log10(n)-log10(exp(1.0)))) + 1;
}
