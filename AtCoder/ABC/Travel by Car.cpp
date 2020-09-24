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

int l;
pi dist[305][305];
vector<pi> g[305];

bool lss(pi a, pi b){
	if(a.fi != b.fi) return a.fi < b.fi;
	return a.se > b.se;
}

struct cmp{
	bool operator() (pair<pi, int> a, pair<pi, int> b){
		if(a.fi.fi != b.fi.fi) return a.fi.fi < b.fi.fi;
		else if(a.fi.se != b.fi.se) return a.fi.se > b.fi.se;
		return a.se > b.se;
	}
};

void dijkstra(int source){
	dist[source][source] = {0, l};
	set<pair<pi, int>, cmp> q;
	q.insert(mp(dist[source][source], source));
	while(!q.empty()){
		pair<pi, int> cur = *q.begin();
		q.erase(q.begin());
		for(pi x : g[cur.se]) if(x.se <= l){
			pi nw = cur.fi;
			if(x.se <= nw.se) nw.se -= x.se;
			else{
				nw.fi++;
				nw.se = l - x.se;
			}
			if(lss(nw, dist[source][x.fi])){
				q.erase(mp(dist[source][x.fi], x.fi));
				dist[source][x.fi] = nw;
				q.insert(mp(dist[source][x.fi], x.fi));
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
	cin >> n >> m >> l;
	rep(i, 305) rep(j, 305) dist[i][j] = {1e9, 0};
	rep(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
        	g[a].pb(mp(b, c));
        	g[b].pb(mp(a, c));
	}
	rep(i, n) dijkstra(i);
	int q;
	cin >> q;
	rep(i, q){
		int s, t;
        	cin >> s >> t;
        	if(dist[s - 1][t - 1].fi == 1e9) cout << -1 << endl;
        	else cout << dist[s - 1][t - 1].fi << endl;
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
