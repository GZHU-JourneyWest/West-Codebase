// 快速幂求法
inline int rev(int num) {
	return fpow(num, mod-2);
}

// 拓展欧几里得求法
inline int rev(int num) {
	int g, x, y;
	exgcd(num, mod, g, x, y);
	return (x%mod+mod)%mod;
}

// 递推式求法
int inv[1] = 1;
