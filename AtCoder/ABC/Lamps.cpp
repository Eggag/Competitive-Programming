#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
const int mxN = 5e6;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll powt[mxN];
ll u[2005][2005];
ll d[2005][2005];
ll l[2005][2005];
ll r[2005][2005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	ll tot = 0LL;
	rep(i, n) rep(j, m) tot += (s[i][j] == '.');
	rep(i, n){
		l[i][0] = (s[i][0] == '.');
		repn(j, 1, m){
			if(s[i][j] == '.') l[i][j] = 1 + l[i][j - 1];
			else l[i][j] = 0;
		}
		r[i][m - 1] = (s[i][m - 1] == '.');
		for(int j = m - 2; j >= 0; j--){
			if(s[i][j] == '.') r[i][j] = 1 + r[i][j + 1];
			else r[i][j] = 0;
		}
	}
	rep(j, m){
		u[0][j] = (s[0][j] == '.');
		repn(i, 1, n){
			if(s[i][j] == '.') u[i][j] = 1 + u[i - 1][j];
			else u[i][j] = 0;
		}
		d[n - 1][j] = (s[n - 1][j] == '.');
		for(int i = n - 2; i >= 0; i--){
			if(s[i][j] == '.') d[i][j] = 1 + d[i + 1][j];
			else d[i][j] = 0;
		}
	}
	powt[0] = 1LL;
	repn(i, 1, mxN) powt[i] = (2LL * powt[i - 1]) % MOD;
	ll ans = 0LL;
	rep(i, n) rep(j, m) if(s[i][j] == '.'){
		ll nm = 1 + (u[i][j] - 1) + (d[i][j] - 1) + (l[i][j] - 1) + (r[i][j] - 1);
		(ans += ((powt[nm] - 1 + MOD) * powt[tot - nm])) %= MOD;
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
