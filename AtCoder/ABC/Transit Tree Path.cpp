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

ll dist[200005]; //don't forget to initialize to inf, change to ll if necessary

void dijkstra(int t){
	//find the shortest paths to t
	rep(i, 100005) dist[i] = 1e18;
	dist[t] = 0;
	set<pi> q;
	q.insert(mp(dist[t], t));
	while(!q.empty()){
		int u = q.begin() -> se;
		q.erase(q.begin());
		for(pi x : g[u]){
			if((dist[u] + x.se) < dist[x.fi]){
				q.erase(mp(dist[x.fi], x.fi));
				dist[x.fi] = dist[u] + x.se;
				q.insert(mp(dist[x.fi], x.fi));
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n - 1){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}
	int q, k;
	cin >> q >> k;
	k--;
	dijkstra(k);
	rep(i, q){
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << dist[x] + dist[y] << endl;
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
