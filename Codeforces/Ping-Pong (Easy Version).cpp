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

bool overlap(pi a, pi b){
	if(a.fi < b.se && a.fi > b.fi) return 1;
	if(a.se < b.se && a.se > b.fi) return 1;
	return 0;
}

int vis[105];
vi g[105];

void dfs(int cur){
	vis[cur] = 1;
	for(auto x : g[cur]) if(!vis[x]) dfs(x);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p;
	rep(i, n){
		int t;
		cin >> t;
		if(t == 1){
			int x, y;
			cin >> x >> y;
			rep(j, p.size()){
				if(overlap(p[j], mp(x, y))) g[j].pb((int)p.size());
				if(overlap(mp(x, y), p[j])) g[(int)p.size()].pb(j);
			}
			p.pb({x, y});
		}
		else{
			int a, b;
			cin >> a >> b;
			a--, b--;
			memset(vis, 0, sizeof(vis));
			dfs(a);
			if(vis[b]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
