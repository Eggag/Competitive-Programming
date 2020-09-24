ll mypow(ll a, ll p, ll MOD){
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1, MOD) % MOD)) % MOD;
	ll x = mypow(a, p / 2, MOD) % MOD;
	return (x * x) % MOD;
}

void computeInvs(){
	inv1[0] = 1;
	for(int j = 1; j <= 1000000; j++){
      		if(j == 1) inv1[j] = mypow(p, m - 2, m);
		else inv1[j] = (inv1[j - 1] * inv1[1]) % m;
	}
	inv2[0] = 1;
	for(int j = 1; j <= 1000000; j++){
      		if(j == 1) inv2[j] = mypow(p1, m1 - 2, m1);
		else inv2[j] = (inv2[j - 1] * inv2[1]) % m1;
	}
}
