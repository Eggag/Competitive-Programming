ll fact[mxN];
ll invFact[mxN];

ll C(ll n, ll r){
	if(r > n) return 0;
	ll ret = fact[n];
	ret = ((ret * invFact[n - r]) + MOD) % MOD;
	ret = ((ret * invFact[r]) + MOD) % MOD;
	return ret;
}

ll mypow(ll a, ll p){
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1) % MOD)) % MOD;
	ll x = mypow(a, p / 2) % MOD;
	return (x * x) % MOD;
}

ll inv(ll base){
	return mypow(base, MOD - 2);
}


//in main

fact[0] = 1;
invFact[0] = 1;
fact[0] = 1;
for(ll i = 1LL; i < mxN; i++) fact[i] = (1LL * fact[i - 1] * i) % MOD;
for(ll i = mxN - 1; i >= 0LL; i--){
	if(i == (mxN - 1)) invFact[i] = inv(fact[i]);
	else invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}