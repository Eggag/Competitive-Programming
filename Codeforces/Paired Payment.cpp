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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> g[mxN];
int dist[mxN][55];

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
		a--, b--;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}
	rep(i, mxN) rep(j, 55) dist[i][j] = 1e9;
	dist[0][0] = 0;
	set<pair<int, pi>> q;
	q.insert(mp(0, mp(0, 0)));
	while(!q.empty()){
		pair<int, pi> cr = *q.begin();
		q.erase(q.begin());
		if(cr.se.se){
			for(pi x : g[cr.se.fi]){
				int rn = cr.fi + sq(x.se + cr.se.se);
				if(rn < dist[x.fi][0]){
					q.erase(mp(dist[x.fi][0], mp(x.fi, 0)));
					dist[x.fi][0] = rn;
					q.insert(mp(dist[x.fi][0], mp(x.fi, 0)));
				}
			}
		}
		else{
			for(pi x : g[cr.se.fi]){
				int rn = cr.fi;
				if(rn < dist[x.fi][x.se]){
					q.erase(mp(dist[x.fi][x.se], mp(x.fi, x.se)));
					dist[x.fi][x.se] = rn;
					q.insert(mp(dist[x.fi][x.se], mp(x.fi, x.se)));
				}
			}
		}
	}
	rep(i, n){
		if(dist[i][0] == 1e9) dist[i][0] = -1;
		cout << dist[i][0] << " ";
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
