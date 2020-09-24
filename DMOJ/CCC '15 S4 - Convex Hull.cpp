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
const int mxN = 2e3 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int k, n, m;
vector<array<int, 3>> g[mxN];
ll dist[mxN][205];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> k >> n >> m;
	rep(i, m){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--;
		g[a].pb({b, c, d});
		g[b].pb({a, c, d});
	}
	int A, B;
	cin >> A >> B;
	A--, B--;
	rep(i, mxN) rep(j, k + 1) dist[i][j] = 1e18;
	dist[A][k] = 0;
	set<pair<int, pi>> q;
	q.insert(mp(0, mp(A, k)));
	while(!q.empty()){
		pair<int, pi> cur1 = *q.begin();
		pi cur = cur1.se;
		q.erase(q.begin());
		for(array<int, 3> x : g[cur.fi]) if(cur.se > x[2]){
			if((dist[cur.fi][cur.se] + x[1]) < dist[x[0]][cur.se - x[2]]){
				q.erase(mp(dist[x[0]][cur.se - x[2]], mp(x[0], cur.se - x[2])));
				dist[x[0]][cur.se - x[2]] = dist[cur.fi][cur.se] + x[1];
				q.insert(mp(dist[x[0]][cur.se - x[2]], mp(x[0], cur.se - x[2])));
			}
		}
	}
	ll ans = 1e18;
	rep(i, k + 1) ans = min(ans, dist[B][i]);
	if(ans >= 1e14) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
