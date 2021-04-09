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
#define inf 0x3f3f3f3f
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN];
int v[mxN][mxN];
ll hsh[2][5005];
ll pows[2][5005];
ll MOD = 1e9 + 7, MOD2 = 1e9 + 9;

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
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
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
	set<pair<ll, ll>> cnt;
	rep(len, n){
		repn(i, len, n - len){
			cnt.insert(comp_hs(i - 1 - len, i - 1));
			pair<ll, ll> cr = comp_hs(i, i + len);
			if(cnt.find(cr) != cnt.end())  v[i][i + len] = 1;
		}
		cnt.clear();
	}
	memset(dp, inf, sizeof(dp));
	dp[0] = a;
	rep(i, n){
		dp[i + 1] = min(dp[i + 1], dp[i] + a);
		repn(j, i + 1, n){
			if(v[i + 1][j]) dp[j] = min(dp[j], dp[i] + b);
			else break;
		}
	}
	cout << dp[n - 1] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
