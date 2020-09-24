#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const int maxn = 105;

vector<pi> g[maxn];
int v[maxn];

bool dfs(int cur, int goal, int color){
	v[cur] = 1;
	if(cur == goal) return 1;
	for(pi u : g[cur]) if(!v[u.fi] && u.se == color){
		if(dfs(u.fi, goal, color)) return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}
	int q;
	cin >> q;
	while(q--){
		int u, x;
		cin >> u >> x;
		int cnt = 0;
		repn(i, 1, maxn){
			memset(v, 0, sizeof(v));
			if(dfs(u, x, i)) cnt++;
		}
		cout << cnt << endl;
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
