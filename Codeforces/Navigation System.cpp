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
vi g1[200005];
int dist[200005];
int t;

void dijkstra(){
	//find the shortest paths to t
	rep(i, 200005) dist[i] = 1e9;
	dist[t] = 0;
	set<pi> q;
	q.insert(mp(dist[t], t));
	while(!q.empty()){
		int u = q.begin() -> se;
		q.erase(q.begin());
		for(int x : g[u]){
			if((dist[u] + 1) < dist[x]){
				q.erase(mp(dist[x], x));
				dist[x] = dist[u] + 1;
				q.insert(mp(dist[x], x));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g1[u].pb(v);
		g[v].pb(u);
	}
	int k;
	cin >> k;
	vi p(k);
	rep(i, k) cin >> p[i], p[i]--;
	t = p[k - 1];
	dijkstra();
	int mn = 0;
	int mx = 0;
	rep(i, k - 1){
		if((dist[p[i]]) != (dist[p[i + 1]] + 1)) mn++, mx++;
		int f = 0;
		for(int j : g1[p[i]]) if(dist[j] == dist[p[i + 1]]) f++;
		if(f > 1 && !(dist[p[i]] - (dist[p[i + 1]] + 1))) mx++;
	}
	cout << mn << " " << mx << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
