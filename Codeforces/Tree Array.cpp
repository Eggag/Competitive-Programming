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
const int mxN = 205;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int up[mxN][10];
ll p[mxN][mxN];
int st[mxN], en[mxN], d[mxN];
int cnt = 0;

void dfs(int cur, int prev, int di = 0){
	st[cur] = cnt++;
	d[cur] = di;
	up[cur][0] = prev;
	repn(i, 1, 10) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for(int x : g[cur]) if(x != prev) dfs(x, cur, di + 1);
	en[cur] = cnt++;
}

bool upper(int a, int b){
	return st[a] <= st[b] && en[a] >= en[b];
}

int lca(int a, int b){
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	for(int i = 9; i >= 0; i--) if(!upper(up[a][i], b)) a = up[a][i];
	return up[a][0];
}

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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n;
	cin >> n;
	rep(i, n - 1){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	p[0][0] = 1LL;
	rep(i, mxN - 1){
		rep(j, i + 1){
			int k = i - j;
			(p[j + 1][k] += (p[j][k] * inv(2)) % MOD) %= MOD;
			(p[j][k + 1] += (p[j][k] * inv(2)) % MOD) %= MOD;
		}
	}
	rep(k, n) repn(j, 1, n) (p[j][k] += p[j - 1][k]) %= MOD;
	ll ans = 0LL;
	rep(i, n){
		cnt = 0;
		dfs(i, i);
		rep(j, n) repn(k, j + 1, n){
			if(upper(k, j)) ans++;
			else if(!upper(j, k)){
				int c = lca(j, k);
				int a = d[j] - d[c], b = d[k] - d[c];
				(ans += (p[a - 1][b - 1] * inv(2)) % MOD) %= MOD;
			}
		}
	}
	cout << (ans * inv(n)) % MOD << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
