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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dist[mxN];
vector<pair<int, ll>> g[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int a, b;
		ll w;
		cin >> a >> b >> w;
		a--, b--;
		g[a].pb({b, w});
		g[b].pb({a, w});
	}
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	rep(i, mxN) dist[i] = 1e18;
	rep(i, n) dist[i] = a[i];
	set<pair<ll, int>> q;
	rep(t, n) q.insert(mp(dist[t], t));
	while(!q.empty()){
		int u = q.begin() -> se;
		q.erase(q.begin());
		for(pair<int, ll> x : g[u]){
			if((dist[u] + 2 * (x.se)) < dist[x.fi]){
				q.erase(mp(dist[x.fi], x.fi));
				dist[x.fi] = dist[u] + 2 * x.se;
				q.insert(mp(dist[x.fi], x.fi));
			}
		}
	}
	rep(i, n) cout << dist[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
