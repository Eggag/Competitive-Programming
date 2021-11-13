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
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int mxN = 305;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll hsh[2][100005];
ll pows[2][100005];
map<pair<ll, ll>, int> hs[mxN];

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
	int n;
	cin >> n;
	vector<string> s(n);
	vi st(n, 0);
	string t = "";
	int tot = 0;
	rep(i, n){
		cin >> s[i];
		if(i) tot++;
		tot += (int)(s[i].size());
		st[i] = (int)(t.size());
		t += s[i];
		t += ' ';
	}
	pows[0][0] = pows[1][0] = 1;
	for(int i = 1; i <= (int)(t.size()); i++){
		pows[0][i] = (pows[0][i - 1] * 179) % MOD;
		pows[1][i] = (pows[1][i - 1] * 131) % MOD2;
	}
	for(int i = 1; i <= (int)(t.size()); i++){
		hsh[0][i] = (hsh[0][i - 1] * 179) + (ll)(t[i - 1] - 'a') + 1;
		hsh[1][i] = (hsh[1][i - 1] * 131) + (ll)(t[i - 1] - 'a') + 1;
		hsh[0][i] %= MOD;
		hsh[1][i] %= MOD2;
	}
	int ans = tot;
	rep(i, n){
		int nm = 0;
		rep(j, n) if(s[i] == s[j]) nm++;
		if(nm > 1) ans = min(ans, tot - nm * ((int)(s[i].size()) - 1));
	}
	repn(len, 1, n){
		vector<pair<ll, ll>> hh(n);
		rep(i, n) hs[i].clear();
		repn(i, len, n){
			int l = st[i - len], r = st[i] + (int)(s[i].size()) - 1;
			hh[i] = comp_hs(l, r);
			int nm = 0;
			rep(j, i - len) nm = max(nm, hs[j][hh[i]]);
			nm++;
			hs[i][hh[i]] = nm;
			if(nm > 1){
				ans = min(ans, tot - nm * ((r - l + 1) - (len + 1)));
			}
		}
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
