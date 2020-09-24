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

vector<pi> g[105];
int dist[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, c;
	cin >> n >> m >> c;
	int a, b;
	cin >> a >> b;
	a--, b--;
	vi p(n);
	rep(i, n) cin >> p[i];
	rep(i, m){
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		g[x].pb(mp(y, z));
		g[y].pb(mp(x, z));
	}
	rep(i, 105) rep(j, 105) dist[i][j] = 1e9;
	dist[a][0] = 0;
	set<pair<int, pi>> q;
	q.insert(mp(0, mp(a, 0)));
	while(!q.empty()){
		pi cur = q.begin() -> se;
		q.erase(q.begin());
		int amt = cur.se;
		int add = 0;
		while(amt <= c){
			for(pi x : g[cur.fi]){
				if(amt >= x.se && (dist[cur.fi][cur.se] + add + 1) < (dist[x.fi][amt - x.se])){
					q.erase(mp(dist[x.fi][amt - x.se], mp(x.fi, amt - x.se)));
					dist[x.fi][amt - x.se] = dist[cur.fi][cur.se] + add + 1;
					q.insert(mp(dist[x.fi][amt - x.se], mp(x.fi, amt - x.se)));
				}
			}
			if(c - amt == 0) break;
			amt += min(c - amt, p[cur.fi]);
			add++;
		}
	}
	int ans = 1e9;
	rep(i, 105) ans = min(ans, dist[b][i]);
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
