#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

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


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	Frac ans(0, 1); //the prob
	Frac next(1, 1);
	rep(i, n){
		//debug2(next.A, next.B);
		if(a[i] == 0 && b[i] == 0){
			Frac prob((m * (m - 1)) / 2, m); //not quite 1/2???
			prob *= Frac(1, m);
			//debug2(prob.A, prob.B);
			ans += (next * prob);
			next *= Frac(1, m); //only if they are equal
		}
		else if(a[i] == 0){
			ans += (next * Frac(m - b[i], m));
			next *= Frac(1, m); //only if they are equal
		}
		else if(b[i] == 0){
			ans += (next * Frac(a[i] - 1, m));
			next *= Frac(1, m); //only if they are equal
		}
		else{
			if(a[i] < b[i]) break;
			if(a[i] > b[i]){
				ans += next * Frac(1, 1);
				break;
			}
		}
	}
	cout << ans.ans() << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
