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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ll len, dist[mxN];
vector<pair<int, ll>> g[mxN];
vector<vi> up;
ll cnt[mxN];
int l = 1;

void dfs(int cur, int prev = 0, ll d = 0LL){
	dist[cur] = d;
	up[cur][0] = prev;
	repn(i, 1, l + 1) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for(pair<int, ll> x : g[cur]) if(x.fi != prev) dfs(x.fi, cur, d + x.se);
}

void dfs1(int cur, int prev){
	for(pair<int, ll> x : g[cur]) if(x.fi != prev){
		dfs1(x.fi, cur);
		cnt[cur] += cnt[x.fi];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("runaway.in", "r", stdin);
	freopen("runaway.out", "w", stdout);
	int n;
	ll len;
	cin >> n >> len;
	repn(i, 1, n){
		int a;
		ll b;
		cin >> a >> b;
		a--;
		g[a].pb({i, b});
		g[i].pb({a, b});
	}
	up.resize(n + 1);
	while((1 << l) <= n) l++;
	rep(i, n) up[i].resize(l + 1);
	dfs(0);
	rep(i, n){
		cnt[i]++;
		int nxt = i;
		for(int j = l; j >= 0; j--){
			int nd = up[nxt][j];
			if((dist[i] - dist[nd]) <= len) nxt = nd;
		}
		if(nxt) cnt[up[nxt][0]]--;
	}
	dfs1(0, -1);
	rep(i, n) cout << cnt[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
