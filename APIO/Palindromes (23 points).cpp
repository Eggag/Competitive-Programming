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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

pair<ll, ll> hsh[10005];
ll inv1[10005], inv2[10005];
ll p = 349, p1 = 179, m = 1e9 + 7, m1 = 1e9 + 9;
 
void computeHashes(string s){
	ll hash_value1 = 0, hash_value2 = 0;
	ll p_pow1 = 1, p_pow2 = 1;
	int cnt = 0;
	for(char c : s){
		hash_value1 = (hash_value1 + (c - '0' + 1) * p_pow1) % m;
		hash_value2 = (hash_value2 + (c - '0' + 1) * p_pow2) % m1;
		hsh[cnt] = mp(hash_value1, hash_value2);
		cnt++;
		p_pow1 = (p_pow1 * p) % m;
		p_pow2 = (p_pow2 * p1) % m1;
	}
}
 
ll mypow(ll a, ll p, ll MOD){
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1, MOD) % MOD)) % MOD;
	ll x = mypow(a, p / 2, MOD) % MOD;
	return (x * x) % MOD;
}
 
void computeInvs(){
	inv1[0] = 1;
	for(int j = 1; j <= 10000; j++){
      		if(j == 1) inv1[j] = mypow(p, m - 2, m);
		else inv1[j] = (inv1[j - 1] * inv1[1]) % m;
	}
	inv2[0] = 1;
	for(int j = 1; j <= 10000; j++){
      		if(j == 1) inv2[j] = mypow(p1, m1 - 2, m1);
		else inv2[j] = (inv2[j - 1] * inv2[1]) % m1;
	}
}
 
pair<ll, ll> comp_hs(int i, int j){
	ll hs1 = ((hsh[j].fi - (i ? hsh[i - 1].fi : 0)) + m) % m;
	ll hs2 = ((hsh[j].se - (i ? hsh[i - 1].se : 0)) + m1) % m1;
	(hs1 *= inv1[i]) %= m;
	(hs2 *= inv2[i]) %= m1;
	return mp(hs1, hs2);
}

int pal[10005][10005]; //is s[i : j] a palindrome?

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	computeInvs();
	computeHashes(s);
	rep(i, n) pal[i][i] = 1;
	rep(i, n - 1) if(s[i] == s[i + 1]) pal[i][i + 1] = 1;
	repn(i, 2, n){
		rep(j, n - i + 1){
			if(s[j] == s[j + i] && pal[j + 1][j + i - 1]) pal[j][j + i] = 1;
		}
	}
	map<pair<ll, ll>, pi> m;
	rep(i, n) repn(j, i, n) if(pal[i][j]){
		pair<ll, ll> cr = comp_hs(i, j);
		m[cr].fi = (j - i + 1);
		m[cr].se++;
	}	
	ll ans = 0;
	for(pair<pair<ll, ll>, pi> x : m){
		ans = max(ans, (ll)(x.se.se * x.se.fi));
	}
	cout << ans << endl;	
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
