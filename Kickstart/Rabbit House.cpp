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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int mxN = 305;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
int g[mxN][mxN], g1[mxN][mxN];
int vis[mxN][mxN];

bool valid(pi cur){
	return min(cur.fi, cur.se) >= 0 && cur.fi < n && cur.se < m;
}

ll solve(){
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j], g1[i][j] = -1;
	set<pair<int, pi>> q;
	rep(i, n) rep(j, m) q.insert(mp(g[i][j], mp(i, j)));
	ll ans = 0LL;
	while(!q.empty()){
		pair<int, pi> cur = *(--q.end());
		q.erase(--q.end());
		g1[cur.se.fi][cur.se.se] = cur.fi;
		rep(j, 4){
			pi nw = mp(cur.se.fi + dx[j], cur.se.se + dy[j]);
			if(valid(nw) && g1[nw.fi][nw.se] == -1){
				q.erase(mp(g[nw.fi][nw.se], nw));
				int cr = max(g[nw.fi][nw.se], cur.fi - 1);
				g1[nw.fi][nw.se] = cr;
				q.insert(mp(cr, nw));
			}
		}
	}
	rep(i, n) rep(j, m) ans += g1[i][j] - g[i][j];
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
