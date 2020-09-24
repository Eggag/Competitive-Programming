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

int n;
string s;
pair<ll, ll> hsh[5005], c_hs[5005][5005];
ll inv1[5005];
ll inv2[5005];
ll p = 31, p1 = 179;
ll m = 1e9 + 9, m1 = 1e9 + 7;

pair<ll, ll> compute_hash(string s1){
	long long hash_value = 0, hash_value1 = 0;
	long long p_pow = 1, p_pow1 = 1;
	for(char c : s1){
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
		hash_value1 = (hash_value1 + (c - 'a' + 1) * p_pow1) % m1;
		p_pow1 = (p_pow1 * p1) % m1;
	}
	return mp(hash_value, hash_value1);
}

void computeHashes(){
	repn(i, 1, n + 1){
		string s1 = s.substr(0, i);
		hsh[i - 1] = compute_hash(s1);
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
	ll mult1 = 1LL, mult2 = 1LL;
	rep(i, 5005){
		inv1[i] = mypow(mult1, m - 2, m);
		(mult1 *= p) %= m;
	}
	rep(i, 5005){
		inv2[i] = mypow(mult2, m1 - 2, m1);
		(mult2 *= p1) %= m1;
	}
}

void comp_hs(int i, int j){
	ll hs1 = ((hsh[j].fi - (i ? hsh[i - 1].fi : 0)) + m) % m;
	ll hs2 = ((hsh[j].se - (i ? hsh[i - 1].se : 0)) + m1) % m1;
	(hs1 *= inv1[i]) %= m;
	(hs2 *= inv2[i]) %= m1;
	c_hs[i][j] = mp(hs1, hs2);
}

bool eq(pair<ll, ll> a, pair<ll, ll> b){
	return (a.fi == b.fi && a.se == b.se);
}

bool check(int len){
	rep(i, n - (2 * len) + 1) repn(j, i + len, n - len + 1){
		if(eq(c_hs[i][i + len - 1], c_hs[j][j + len - 1])) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	cin >> s;
	vi cnt(30, 0);
	int f = 1;
	rep(i, n){
		if(cnt[s[i] - 'a']){
			f = 0;
			break;
		}
		cnt[s[i] - 'a']++;
	}
	if(f){
		cout << 0 << endl;
		return 0;
	}
	computeHashes();
	computeInvs();
	rep(i, n) repn(j, i, n) comp_hs(i, j);
	int l = 1, r = n / 2;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
