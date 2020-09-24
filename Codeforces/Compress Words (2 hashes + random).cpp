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

string ans = "";
int maxLen = 0;
pair<ll, ll> hsh[1000005], hshA[1000005];
string s[1000005];
ll inv1[1000005], inv2[1000005];
ll p = 349, p1 = 449, m = 1e9 + 7, m1 = 1e9 + 9;
vector<ll> primes = {349, 449, 2011, 7919, 8191};
vector<ll> mods = {1000000007, 1000000009, 701246983, 801237469, 301246597};

 
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

ll hash_value = 0, hash_value3 = 0;
int len = 0;
ll p_pow = 1, p_pow3 = 1;

void computeHashesAns(){
	while(len < (int)(ans.size())){
		hash_value = (hash_value + (ans[len] - '0' + 1) * p_pow) % m;
		hash_value3 = (hash_value3 + (ans[len] - '0' + 1) * p_pow3) % m1;
		hshA[len] = mp(hash_value, hash_value3);
		p_pow = (p_pow * p) % m;
		p_pow3 = (p_pow3 * p1) % m1;
		len++;
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
 
pair<ll, ll> comp_hs(int i, int j){
	ll hs1 = ((hsh[j].fi - (i ? hsh[i - 1].fi : 0)) + m) % m;
	ll hs2 = ((hsh[j].se - (i ? hsh[i - 1].se : 0)) + m1) % m1;
	(hs1 *= inv1[i]) %= m;
	(hs2 *= inv2[i]) %= m1;
	return mp(hs1, hs2);
}
 
pair<ll, ll> comp_hs_ans(int i, int j){
	ll hs1 = ((hshA[j].fi - (i ? hshA[i - 1].fi : 0)) + m) % m;
	ll hs2 = ((hshA[j].se - (i ? hshA[i - 1].se : 0)) + m1) % m1;
	(hs1 *= inv1[i]) %= m;
	(hs2 *= inv2[i]) %= m1;
	return mp(hs1, hs2);
}

bool eq(pair<ll, ll> a, pair<ll, ll> b){
	return (a.fi == b.fi && a.se == b.se);
}

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n) cin >> s[i], maxLen += (int)s[i].size();
	p = primes[(int)(rng() % 5)];
	while(p == p1){
		ll ind = rng() % 5;
		p1 = primes[ind];
	}
	m = mods[(int)(rng() % 5)];
	while(m == m1){
		ll ind = rng() % 5;
		m1 = mods[ind];
	}
	computeInvs();
	rep(i, n){
		if(!i) ans += s[i];
		else{
			computeHashes(s[i]);
			computeHashesAns(); //keep adding on?
			int l = 0;
			repn(j, 1, min(ans.size(), s[i].size()) + 1){
				if(eq(comp_hs(0, j - 1), comp_hs_ans(ans.size() - 1 - (j - 1), ans.size() - 1))) l = j;
			}
			ans += s[i].substr(l, s[i].size() - l);
		}
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
