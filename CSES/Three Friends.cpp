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

pair<ll, ll> hsh[2000005];
ll inv1[2000005], inv2[2000005];
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
	for(int j = 1; j <= 2000000; j++){
      		if(j == 1) inv1[j] = mypow(p, m - 2, m);
		else inv1[j] = (inv1[j - 1] * inv1[1]) % m;
	}
	inv2[0] = 1;
	for(int j = 1; j <= 2000000; j++){
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n % 2 == 0){
		cout << "NOT POSSIBLE" << endl;
		return 0;
	}
	char ch = 'z';
	vi cnt(30, 0);
	rep(i, n) cnt[s[i] - 'A']++;
	rep(i, 30) if(cnt[i] & 1) ch = (char)('A' + i);
	assert(ch != 'z');
	set<pair<ll, ll>> st;
	vi pref(n / 2 + 1, 0), suf(n / 2 + 1, 0);
	int len = n / 2;
	rep(i, n / 2 + 1){
		if(s[i] != s[i + len + 1]) break;
		else pref[i] = 1;
	}
	for(int i = n / 2; i >= 1; i--){
		if(s[i] != s[i + len]) break;
		else suf[i] = 1;
	}
	string ans = "";
	computeInvs();
	computeHashes(s);	
	repn(i, 1, n / 2) if(s[i] == ch){
		if(pref[i - 1] && suf[i + 1]){
			//string c = s.substr(n / 2 + 1, len);
			//st.insert(c);
			if(!ans.size()){
				ans = s.substr(n / 2 + 1, len);
			}
			st.insert(comp_hs(n / 2 + 1, n / 2 + 1 + (len - 1)));
			if(st.size() > 1){
				cout << "NOT UNIQUE" << endl;
				return 0;
			}
		}
	}
	vi pref1(n, 0), suf1(n, 0);
	for(int i = n - 1; i >= n / 2; i--){
		if(s[i] !=  s[i - len - 1]) break;
		else suf1[i] = 1;
	}
	repn(i, n / 2, n){
		if(s[i] !=  s[i - len]) break;
		else pref1[i] = 1;
	}
	repn(i, n / 2 + 1, n) if(s[i] == ch){
		if(pref1[i - 1] && suf1[i + 1]){
			//string c = s.substr(0, len);
			//st.insert(c);
			st.insert(comp_hs(0, len - 1));
			if(!ans.size()){
				ans = s.substr(0, len);
			}
			if(st.size() > 1){
				cout << "NOT UNIQUE" << endl;
				return 0;
			}
		}
	}
	string a1 = s.substr(1, len), a2 = s.substr(len + 1, len);
	if(a1 == a2){
		st.insert(comp_hs(1, len));
		if(!ans.size()) ans = a1;
	}
	a1 = s.substr(0, len), a2 = s.substr(len + 1, len);
	if(a1 == a2){
		st.insert(comp_hs(0, len - 1));
		if(!ans.size()) ans = a1;
	}
	a1 = s.substr(0, len), a2 = s.substr(len, len);
	if(a1 == a2){
		st.insert(comp_hs(0, len - 1));
		if(!ans.size()) ans = a1;
	}
	if(!st.size()) cout << "NOT POSSIBLE" << endl;
	else if(st.size() == 1) cout << ans << endl;
	else cout << "NOT UNIQUE" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
