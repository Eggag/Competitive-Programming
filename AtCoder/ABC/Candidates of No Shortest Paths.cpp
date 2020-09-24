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

int n, m;
vector<pi> g[105];
map<pi, int> vis;
int dist[105], p[105];

void dijkstra(int s){
	rep(i, 105) dist[i] = 1e9, p[i] = -1;
	p[s] = -1;
	dist[s] = 0;
	set<pi> q;
	q.insert(mp(dist[s], s));
	while(!q.empty()){
		int cur = q.begin() -> se;
		q.erase(q.begin());
		for(pi x : g[cur]){
			if((dist[cur] + x.se) < (dist[x.fi])){
				q.erase(mp(dist[x.fi], x.fi));
				p[x.fi] = cur;
				dist[x.fi] = dist[cur] + x.se;
				q.insert(mp(dist[x.fi], x.fi));
			}
		}
	}
	rep(i, n){
		int prev = i;
		int pr = p[prev];
		while(pr != -1){
			vis[mp(pr, prev)] = 1;
			vis[mp(prev, pr)] = 1;
			prev = p[prev];
			pr = p[prev];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	vi a(m), b(m), c(m);
	rep(i, m){
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
		g[a[i]].pb(mp(b[i], c[i]));
		g[b[i]].pb(mp(a[i], c[i]));
	}
	rep(i, n) dijkstra(i);
	int ans = 0;
	rep(i, m) if(!vis[mp(a[i], b[i])]) ans++;
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
