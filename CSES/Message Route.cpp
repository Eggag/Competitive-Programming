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
int dist[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	vi p(n);
	p[0] = -1;
	rep(i, n) dist[i] = 1e9;
	dist[0] = 0;
	set<pi> q;
	q.insert(mp(0, dist[0]));
	while(!q.empty()){
		int u = q.begin() -> fi;
		q.erase(q.begin());
		for(int v : g[u]){
			if(dist[v] > (dist[u] + 1)){
				q.erase(mp(v, dist[v]));
				p[v] = u;
				dist[v] = dist[u] + 1;
				q.insert(mp(v, dist[v]));
			}
		}
	}
	if(dist[n - 1] == 1e9) cout << "IMPOSSIBLE" << endl;
	else{
		cout << dist[n - 1] + 1 << endl;
		vi ans = {n - 1};
		int cur = n - 1;
		while(p[cur] != -1){
			ans.pb(p[cur]);
			cur = p[cur];
		}
		for(int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i] + 1 << " ";
		cout << endl;
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
