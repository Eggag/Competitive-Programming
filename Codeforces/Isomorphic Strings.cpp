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
const int mxN = 2e5 + 5;
const ll MOD = 1e9 + 7, MOD2 = 1e9 + 9;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[26][mxN], p[26][mxN];
vector<ll> hsh[26], hsh1[26];
ll pows[2][mxN];

pair<ll, ll> comp_hs(int c, int l, int r){
	ll h1 = (((hsh[c][r] - (l ? hsh[c][l - 1] : 0) * pows[0][(r - l + 1)]) % MOD) + MOD) % MOD;
	ll h2 = (((hsh1[c][r] - (l ? hsh1[c][l - 1] : 0) * pows[1][(r - l + 1)]) % MOD2) + MOD2) % MOD2;
	return mp(h1, h2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	pows[0][0] = pows[1][0] = 1;
	for(int i = 1; i < mxN; i++){
		pows[0][i] = (ll)(1LL* pows[0][i - 1] * 1000159) % MOD;
		pows[1][i] = (ll)(1LL * pows[1][i - 1] * 1002299) % MOD2;
	}
	rep(i, 26){
		for(int j = n - 1; j >= 0; j--){
			if((int)(s[j] - 'a') == i) g[i][j] = j;
			else g[i][j] = (j == (n - 1) ? 1e9 : g[i][j + 1]);
		}
		rep(j, n){
			if(j) p[i][j] += p[i][j - 1];
			p[i][j] += ((int)(s[j] - 'a') == i);
		}
		vi dif;
		int lst = -1;
		rep(j, n) if((int)(s[j] - 'a') == i){
			if(lst != -1) dif.pb(j - lst);
			lst = j;
		}
		ll a = 0LL, b = 0LL;
		rep(j, dif.size()){
			a = ((a * 1000159) + dif[j] + 1) % MOD;
			b = ((b * 1002299) + dif[j] + 1) % MOD2;
			hsh[i].pb(a);
			hsh1[i].pb(b);
		}
	}
	rep(i, m){
		int x, y, len;
		cin >> x >> y >> len;
		x--, y--;
		if(y < x) swap(x, y);
		int f = 1;
		vi cnt(26, 0);
		rep(j, 26){
			int cr = g[j][x];		
			if(cr > (x + len - 1)) continue;
			int nx = cr + (y - x);
			int k = (int)(s[nx] - 'a');
			cnt[k]++;
			int nm = p[j][x + len - 1] - (x ? p[j][x - 1] : 0);
			int nm1 = p[k][y + len - 1] - (y ? p[k][y - 1] : 0);
			if(nm != nm1){
				f = 0;
				break;
			}
			if(nm == 1) continue;
			int l = p[j][cr] - 1;
			int r = l + nm - 1;
			if((int)(hsh[j].size()) <= (r - 1)){
				f = 0;
				break;
			}
			pair<ll, ll> hh = comp_hs(j, l, r - 1);
			l = p[k][nx] - 1;
			r = l + nm - 1;
			if((int)(hsh[k].size()) <= (r - 1)){
				f = 0;
				break;
			}
			pair<ll, ll> hh1 = comp_hs(k, l, r - 1);
			if(hh != hh1){
				f = 0;
				break;
			}
		}
		rep(j, 26) if(cnt[j] > 1) f = 0;
		cout << (f ? "YES" : "NO") << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
