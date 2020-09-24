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

vector<pi> g[100005];
int vis[100005];
int loc[100005];

void dfs(int cur, int num){
	if(vis[cur]) return;
	vis[cur] = 1;
	loc[cur] = num;
	for(pi x : g[cur]) dfs(x.fi, num + x.se);
}

int vis1[100005];
vi ord;

void dfs0(int cur){
	vis1[cur] = 1;
	for(pi x : g[cur]) if(!vis1[x.fi]) dfs0(x.fi);
	ord.pb(cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi l(m), r(m), d(m);
	rep(i, m){
		cin >> l[i] >> r[i] >> d[i];
		l[i]--, r[i]--;
		g[l[i]].pb(mp(r[i], d[i])); //hmm lol
		//g[r[i]].pb(mp(l[i], d[i]));
	}
	memset(vis1, 0, sizeof(vis1));
	rep(i, n) if(!vis1[i]) dfs0(i);
	reverse(all(ord));
	memset(vis, 0, sizeof(vis));
	rep(i, n) if(!vis[ord[i]]) dfs(ord[i], 1e7);
	int f = 1;
	rep(i, m){
		if(loc[r[i]] - loc[l[i]] != d[i]){
			f = 0;
			break;
		}
	}
	if(f) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
