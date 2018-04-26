int inv[maxN];
void cal_inv(int n, int mod) 
{
	inv[1] = 1;
	for (int i = 2; i <= n; i++) 
		inv[i] = ((LL(-mod/i)*inv[mod%i])%mod+mod)%mod;
}
