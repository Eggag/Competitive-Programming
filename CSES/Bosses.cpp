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
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int vis[mxN];
ll d[mxN];
vi nxt[mxN], g[mxN];

void dfs(int v){
	d[v] = 1;
	for(int u : g[v]){
		dfs(u);
		d[v] += d[u];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n){
		int k;
		cin >> k;
		rep(j, k){
			int p;
			cin >> p;
			nxt[p - 1].pb(i);
		}
	}
	ll ret = 1e18;
	rep(i, n){
		memset(vis, 0, sizeof(vis));
		memset(d, 0, sizeof(d));
		queue<int> q;
		q.push(i);
		vis[i] = 1;
		rep(j, n) g[j].clear();
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int u : nxt[cur]) if(!vis[u]){
				g[cur].pb(u);
				q.push(u);
				vis[u] = 1;
			}
		}
		dfs(i);
		ll ans = 0LL;
		rep(j, n) ans += d[j];
		int f = 1;
		rep(j, n) if(!vis[j]){
			f = 0;
			break;
		}
		if(f) ret = min(ret, ans);
	}
	cout << ret << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
