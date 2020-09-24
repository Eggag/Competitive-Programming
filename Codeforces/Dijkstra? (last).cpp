#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

ll dist[100005];
set<pair<ll, int>> q;
vector<pi> g[100005];
int p[100005];

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
	rep(i, 100005) dist[i] = 1e18;
	p[1] = -1;
	dist[1] = 0;
	q.insert(mp(dist[1], 1));
	while(!q.empty()){
		int u = q.begin() -> se;
		q.erase(q.begin());
		for(pi v : g[u]){
			int x = v.fi;
			int cost = v.se;
			if((dist[u] + cost) < dist[x]){
				q.erase(mp(dist[x], x));
				dist[x] = dist[u] + cost;
				p[x] = u;
				q.insert(mp(dist[x], x));
			}
		}
	}
	if(dist[n] == 1e18){
		cout << "-1" << endl;
		return 0;
	}	
	vi ans = {n};
	int parent = p[n];
	while(parent != -1){
		ans.pb(parent);
		parent = p[parent];
	}
	reverse(all(ans));
	rep(i, ans.size()){
		cout << ans[i];
		if(i == ans.size() - 1) cout << endl;
		else cout << " ";
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
