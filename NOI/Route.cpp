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
#define ar array

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dist[100001][1001];
vector<ar<int, 3>> g[100001];
int n, m, a, b, c;

int cost(ll t){
	return a * sq(t) + b * t + c;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> a >> b >> c;
	rep(i, m){
		int x, y, p, q;
		cin >> x >> y >> p >> q;
		x--, y--;
		g[x].pb({y, p, q});
	}
	rep(i, n) rep(j, 1001) dist[i][j] = 1e9;
	dist[0][0] = 0;
	set<pair<int, pi>> q;
	q.insert(mp(0, mp(0, 0)));
	while(!q.empty()){
		pair<int, pi> cur = *q.begin();
		q.erase(q.begin());
		for(ar<int, 3> x : g[cur.se.se]){
			if(x[1] >= cur.se.fi){
				if(dist[x[0]][x[2]] > (cur.fi + cost(x[1] - cur.se.fi))){
					q.erase(mp(dist[x[0]][x[2]], mp(x[2], x[0])));
					dist[x[0]][x[2]] = cur.fi + cost(x[1] - cur.se.fi);
					q.insert(mp(dist[x[0]][x[2]], mp(x[2], x[0])));
				}
			}	
		}
	}
	int ans = 1e9;
	rep(i, 1001) ans = min(ans, dist[n - 1][i] + i);
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
