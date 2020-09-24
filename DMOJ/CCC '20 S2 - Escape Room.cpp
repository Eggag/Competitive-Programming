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
int dist[1005][1005];
int g[1005][1005];

bool valid(int x, int y){
	return (x >= 0 && y >= 0 && x < n && y < m);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	unordered_map<int, vector<pi>> m1;
	rep(i, n) rep(j, m) cin >> g[i][j], m1[g[i][j]].pb({i, j});
	set<pair<int, pi>> q;
	rep(i, n) rep(j, m) dist[i][j] = 1e9;
	q.insert(mp(0, mp(n - 1, m - 1)));
	dist[n - 1][m - 1] = 0;
	while(!q.empty()){
		pi cur = q.begin() -> se;
		if(cur.fi == 0 && cur.se == 0){
			cout << "yes" << endl;
			return 0;
		}
		q.erase(q.begin());
		int nxt = (cur.fi + 1) * (cur.se + 1);
		for(pi x : m1[nxt]){
			int a = x.fi, b = x.se;
			if(valid(a, b) && dist[cur.fi][cur.se] + 1 < dist[a][b]){
				q.erase(mp(dist[a][b], mp(a, b)));
				dist[a][b] = dist[cur.fi][cur.se] + 1;
				q.insert(mp(dist[a][b], mp(a, b)));
			}
		}

	}
	cout << "no" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
