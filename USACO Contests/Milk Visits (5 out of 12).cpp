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

vi g[100005];
pi d[100005];
vi v[100005];
string s;

void dfs1(int cur, int prev){
	vi vis;
	if(prev != -1) vis = v[prev];
	vis.pb(cur);
	v[cur] = vis;
	if(prev != -1){
		d[cur].fi = d[prev].fi;
		d[cur].se = d[prev].se;
	}
	d[cur].fi = d[cur].fi + (s[cur] == 'H');
	d[cur].se = d[cur].se + (s[cur] == 'G');
	for(int u : g[cur]) if(u != prev) dfs1(u, cur);
}

int lca(int a, int b){
	int best = 1e9;
	int ans = -1;
	rep(i, v[b].size()){
		rep(j, v[a].size()){
			if((v[b][i] == v[a][j]) && ((v[b].size() - i - 1) + (v[a].size() - j - 1)) < best){
				ans = v[a][j];
				best = (v[b].size() - i - 1) + (v[a].size() - j - 1);
			}
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> s;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs1(0, -1);
	//lets assume it is rooted at 0
	string ans = "";
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		char c;
		cin >> c;
		if(a == b){
			if((s[a] == 'H' && c == 'H') || (s[a] == 'G' && c == 'G')) ans += '1';
			else ans += '0';
			continue;
		}
		int e = lca(a, b);
		int h = (d[a].fi - d[e].fi) + (d[b].fi - d[e].fi) + (s[e] == 'H');
		int g = (d[a].se - d[e].se) + (d[b].se - d[e].se) + (s[e] == 'G');
		if(c == 'H'){
			if(h > 0) ans += '1';
			else ans += '0';
		}
		else{
			if(g > 0) ans += '1';
			else ans += '0';
		}
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

