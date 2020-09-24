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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int p[mxN], h[mxN], d[mxN];
pi req[mxN];
vi g[mxN];
int f = 1;

void dfs0(int cur, int prev){
	d[cur] = p[cur];
	for(int u : g[cur]) if(u != prev){
		dfs0(u, cur);
		d[cur] += d[u];
	}
}

void dfs(int cur, int prev, int happy, int sad){
	for(int u : g[cur]) if(u != prev){
		if(sad < req[u].se){
			if(happy >= (req[u].se - sad)){
				happy -= (req[u].se - sad);
				sad = req[u].se;
			}
			else{
				f = 0;
				return;
			}
		}
		if(req[u].fi > happy){
			f = 0;
			return;
		}
		else happy -= req[u].fi;
		dfs(u, cur, req[u].fi, req[u].se);
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	rep(i, n) cin >> p[i];
	rep(i, n) cin >> h[i];
	rep(i, n) g[i].clear(), d[i] = 0;
	f = 1;
	rep(i, n - 1){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs0(0, -1); //precompute subtree sizes
	rep(i, n){
		//there are d[i] ppl
		//and the difference is h[i]
		if(h[i] < 0){
			int num = (d[i] - abs(h[i])) / 2;
			if(((d[i] - abs(h[i])) % 2) || abs(h[i]) > d[i]){
				cout << "NO" << endl;
				return;
			}
			req[i] = {num, num + abs(h[i])}; //{happy, sad}
		}
		else{
			int num = (d[i] - h[i]) / 2;
			if(((d[i] - h[i]) % 2) || h[i] > d[i]){
				cout << "NO" << endl;
				return;
			}
			req[i] = {num + h[i], num};
		}
	}
	dfs(0, -1, req[0].fi, req[0].se);
	if(f) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
