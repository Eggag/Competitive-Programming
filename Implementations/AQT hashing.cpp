int n;
ll hsh[2][200005]; //change bounds if necessary
ll pows[2][200005];
ll MOD = 1e9 + 7, MOD2 = 1e9 + 9;

pair<ll, ll> comp_hs(int l, int r){ //1 indexed
	ll h1 = (((hsh[0][r] - hsh[0][l - 1] * pows[0][(r - l + 1)]) % MOD) + MOD) % MOD;
	ll h2 = (((hsh[1][r] - hsh[1][l - 1] * pows[1][(r - l + 1)]) % MOD2) + MOD2) % MOD2;
	return mp(h1, h2);
}

pows[0][0] = pows[1][0] = 1;	
for(int i = 1; i <= n; i++){
	pows[0][i] = (pows[0][i - 1] * 179) % MOD;
	pows[1][i] = (pows[1][i - 1] * 131) % MOD2;
}
for(int i = 1; i <= n; i++){
	hsh[0][i] = (hsh[0][i - 1] * 179) + (ll)(s[i - 1] - 'a') + 1;
	hsh[1][i] = (hsh[1][i - 1] * 131) + (ll)(s[i - 1] - 'a') + 1;
	hsh[0][i] %= MOD;
	hsh[1][i] %= MOD2;
}
