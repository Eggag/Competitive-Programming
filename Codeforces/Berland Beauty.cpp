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
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int ed[mxN][mxN];
int v[mxN], pr[mxN];
int st[mxN], en[mxN];
int up[mxN][25];
int t = 0;

void dfs(int cur, int prev = 0){
	st[cur] = t++;
	pr[cur] = prev;
	up[cur][0] = prev;
	repn(i, 1, 21) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for(int x : g[cur]) if(x != prev) dfs(x, cur);
	en[cur] = t++;
}

bool upper(int a, int b){
	return (st[a] <= st[b] && en[a] >= en[b]);
}

int lca(int a, int b){
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	int cr = a;
	for(int i = 20; i >= 0; i--) if(!upper(up[cr][i], b)) cr = up[cr][i];
	return up[cr][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		ed[a][b] = ed[b][a] = i;
	}
	dfs(0);
	int m;
	cin >> m;
	vector<array<int, 3>> p(m);
	rep(i, m){
		cin >> p[i][0] >> p[i][1] >> p[i][2];
		p[i][0]--, p[i][1]--;
		int c = lca(p[i][0], p[i][1]);
		rep(j, 2){
			int cr = p[i][j];
			while(cr != c){
				v[ed[cr][pr[cr]]] = max(v[ed[cr][pr[cr]]], p[i][2]);
				cr = pr[cr];
			}
		}
	}
	rep(i, m){
		int mn = 1e9;
		int c = lca(p[i][0], p[i][1]);
		rep(j, 2){
			int cr = p[i][j];
			while(cr != c){
				mn = min(mn, v[ed[cr][pr[cr]]]);
				cr = pr[cr];
			}
		}
		if(mn != p[i][2]){
			cout << -1 << '\n';
			return 0;
		}
	}
	int mx = 1e6;
	rep(i, n - 1) cout << (v[i] ? v[i] : mx) << " ";
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
