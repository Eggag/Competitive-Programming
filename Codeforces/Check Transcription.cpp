#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
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
const int mxN = 1e6 + 5;
const ll MOD = 1e9 + 7, MOD2 = 1e9 + 9;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll hsh[2][mxN];
ll pows[2][mxN];

pair<ll, ll> comp_hs(int l, int r){
	l++, r++;
	ll h1 = (((hsh[0][r] - hsh[0][l - 1] * pows[0][(r - l + 1)]) % MOD) + MOD) % MOD;
	ll h2 = (((hsh[1][r] - hsh[1][l - 1] * pows[1][(r - l + 1)]) % MOD2) + MOD2) % MOD2;
	return mp(h1, h2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s, t;
	cin >> t >> s;
	set<pair<ll, ll>> on, ze;
	int n = (int)(s.size());
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
	int cnt = 0, cnt1 = 0;
	rep(i, t.size()){
		if(t[i] == '0') cnt++;
		else cnt1++;
	}
	int ans = 0;
	repn(i, 1, n + 1){
		if(cnt1 * i > n) break;
		if((n - (cnt1 * i)) % cnt != 0 || n == (cnt1 * i)) continue;
		int x = i, y = (n - (cnt1 * i)) / cnt;
		int cur = 0;
		rep(j, (int)(t.size())){
			if(t[j] == '0') ze.insert(comp_hs(cur, cur + y - 1)), cur += y;
			else on.insert(comp_hs(cur, cur + x - 1)), cur += x;
			if(on.size() > 1 || ze.size() > 1) break;
		}
		if(on.size() == 1 && ze.size() == 1){
			if(*on.begin() != *ze.begin()) ans++;
		}
		on.clear(), ze.clear();
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
