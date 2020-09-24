#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const ll INF = 1e18;

#ifdef LOCAL
clock_t t = clock();
#endif

vector<pi> g[100005];
ll dist[100005];
int p[100005];
set<pair<ll, int>> q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int a, b, w;
		cin >> a >> b >> w;
		g[a].pb(mp(b, w));
		g[b].pb(mp(a, w));
	}
	repn(i, 1, n + 1){
		dist[i] = INF;
	}
	dist[1] = 0;
	q.insert(mp(dist[1], 1));
	while(!q.empty()){
		int v = q.begin() -> se;
		q.erase(q.begin());
		for(pi e : g[v]){
			int u = e.fi;
			int cost = e.se;
			if(dist[v] + cost < dist[u]){
				q.erase(mp(dist[u], u));
				dist[u] = dist[v] + cost;
				p[u] = v;
				q.insert(mp(dist[u], u));
			}
		}
	}
	if(dist[n] == INF){
		cout << "-1" << endl;
		return 0;
	}
	vi ans;
	int x = n;
	while(x){
		ans.pb(x);
		x = p[x];
	}
	reverse(all(ans));
	rep(i, ans.size()){
		cout << ans[i] << " ";
	}
	cout << endl;
#ifdef LOCAL
	cout << "Total Time: " << (double)(clock() - t) / CLOCKS_PER_SEC << endl;
#endif	
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
