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
 
ll mul(ll A, ll B){
	return (A * B) % MOD;
}
 
ll add(ll A, ll B){
	return (A + B) % MOD;
}
 
ll dvd(ll A, ll B){
    return mul(A, inv(B));
}
 
ll sub(ll A, ll B){
    return (A - B + MOD) % MOD;
}

struct Frac{
	ll A, B;
	Frac(ll X, ll Y){
		A = X; B = Y;
	}
	Frac(){
		A = 0; B = 1;
	}
	ll ans(){
		return dvd(A, B);
	}
	Frac operator+(const Frac& F){
		ll num = add(mul(A, F.B), mul(B, F.A));
		ll den = mul(B, F.B);
		Frac res(num, den);
		return res;
	}
	Frac operator-(const Frac& F){
		ll num = sub(mul(A, F.B), mul(B, F.A));
		ll den = mul(B, F.B);
		Frac res(num, den);
		return res;
	}
	Frac operator*(const Frac& F){
		ll num = mul(A, F.A);
		ll den = mul(B, F.B);
		Frac res(num, den);
		return res;
	}
	Frac operator/(const Frac& F){
		ll num = mul(A, F.B);
		ll den = mul(B, F.A);
		Frac res(num, den);
		return res;
	}
	Frac& operator+=(const Frac& F){ return *this = (*this) + F; }
	Frac& operator-=(const Frac& F){ return *this = (*this) - F; }
	Frac& operator*=(const Frac& F){ return *this = (*this) * F; }
	Frac& operator/=(const Frac& F){ return *this = (*this) / F; }
};
