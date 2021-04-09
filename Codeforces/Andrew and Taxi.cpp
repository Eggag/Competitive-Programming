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

int n, m;
vector<pi> g[mxN];
array<int, 3> ed[mxN];
int vis1[mxN], ind[mxN];
int nw = -1;
vi ord;

void dfs0(int cur){
	vis1[cur] = 1;
	for(pi x : g[cur]) if(x.se > nw) if(!vis1[x.fi]) dfs0(x.fi);
	ord.pb(cur);
}

bool check(int g){
	nw = g;
	memset(vis1, 0, sizeof(vis1));
	ord.clear();
	rep(i, n) if(!vis1[i]) dfs0(i);
	reverse(all(ord));
	rep(i, ord.size()) ind[ord[i]] = i;
	rep(i, m) if(ed[i][2] > g && ind[ed[i][1]] < ind[ed[i][0]]) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		g[a].pb({b, c});
		ed[i] = array<int, 3>{a, b, c};
	}
	int l = 0, r = 1e9 + 5;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	check(l);
	vi ans;
	rep(i, m) if(ed[i][2] <= l){
		if(ind[ed[i][1]] < ind[ed[i][0]]) ans.pb(i);
	}
	cout << l << " " << (int)(ans.size()) << endl;
	for(int x : ans) cout << x + 1 << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
