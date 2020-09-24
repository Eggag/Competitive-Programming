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
const int mxN = 1e4 + 5;
const int MOD = 1e9;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int vis1[mxN], ind[mxN], vis[mxN];
int bad[mxN], ok[mxN];
int dp[mxN], big[mxN];
vi ord;
 
vi g[mxN], in[mxN];

void dfs0(int cur){
	vis1[cur] = 1;
	for(int x : g[cur]) if(!vis1[x]) dfs0(x);
	ord.pb(cur);
}

void dfs(int cur){
	vis[cur] = 1;
	for(int nm : g[cur]) if(!vis[nm]) dfs(nm);
}

void dfs1(int cur){
	ok[cur] = 1;
	for(int nm : g[cur]) if(!ok[nm]) dfs1(nm);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pi> ed;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		ed.pb({a, b});
		in[b].pb(a);
	}
	rep(i, n) if(!vis1[i]) dfs0(i);
	reverse(all(ord));
	rep(i, n) ind[ord[i]] = i;
	rep(i, ed.size()){
		if(ind[ed[i].fi] >= ind[ed[i].se]){
			bad[ed[i].fi] = bad[ed[i].se] = 1;
		}
	}
	dp[0] = 1;
	dfs1(0);
	rep(i, n) if(ok[ord[i]]){
		for(int nm : in[ord[i]]){
			if(bad[ord[i]] && dp[nm]){
				memset(vis, 0, sizeof(vis));
				dfs(ord[i]);
				if(vis[1]){
					cout << "inf" << endl;
					return 0;
				}
			}
			big[ord[i]] |= big[nm];
			if((dp[ord[i]] + dp[nm]) >= MOD) big[ord[i]] = 1;
			(dp[ord[i]] += dp[nm]) %= MOD;
		}
	}
	string ans = to_string(dp[1]);
	if(big[1]){
		reverse(all(ans));
		while(ans.size() < 9) ans += '0';
		reverse(all(ans));
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
