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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> g[mxN];
int uwu[mxN];
int imp = 0;

void dfs(int cur, int prev, int val){
	int cnt = 0;
	for(pi x : g[cur]) if(x.fi != prev) cnt++;
	if(cnt > 2){
		imp = 1;
		return;
	}
	if(cnt == 2){
		if(val){
			imp = 1;
			return;
		}
		int ind = 0;
		for(pi x : g[cur]) if(x.fi != prev){
			if(!ind){
				uwu[x.se] = 2;
				dfs(x.fi, cur, 2);
			}
			else{
				uwu[x.se] = 11;
				dfs(x.fi, cur, 11);
			}
			ind++;
		}
	}
	if(cnt == 1){
		int num = 11;
		if(val & 1) num = 2;
		for(pi x : g[cur]) if(x.fi != prev){
			uwu[x.se] = num;
			dfs(x.fi, cur, num);
		}
	}
}

void solve(){
	int n;
	cin >> n;
	rep(i, n) g[i].clear();
	imp = 0;
	rep(i, n - 1){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(mp(y, i));
		g[y].pb(mp(x, i));
	}
	dfs(0, -1, 0);
	if(imp) cout << "-1\n";
	else{
		rep(i, n - 1) cout << uwu[i] << ' ';
		cout << '\n';
	}
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
