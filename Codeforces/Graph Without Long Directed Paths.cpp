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

vi g[200005];
int col[200005];
int vis[200005];

void dfs(int cur, int prev, int cnt){
	if(vis[cur]){
		if(col[cur] != 0){
			if(cnt != col[cur]){
				cout << "NO" << endl;
				exit(0);
			}
		}
		return;
	}
	vis[cur] = 1;
	col[cur] = cnt;
	int nxt = 2;
	if(cnt == 2) nxt = 1;
	for(int u : g[cur]) if(u != prev){
		dfs(u, cur, nxt);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pi> p;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		p.pb({a, b});
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1, 1);
	cout << "YES" << endl;
	rep(i, m) cout << col[p[i].fi] - 1;
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
