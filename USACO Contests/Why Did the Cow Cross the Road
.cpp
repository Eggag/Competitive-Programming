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
const int mxN = 105;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, t;
int c[mxN][mxN];
ll dist[mxN][mxN][3];

bool valid(int i, int j){
	return (i >= 0 && i < n && j >= 0 && j < n);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);
	cin >> n >> t;
	rep(i, n) rep(j, n) cin >> c[i][j];
	set<pair<ll, array<int, 3>>> q;
	rep(i, mxN) rep(j, mxN) rep(k, 3) dist[i][j][k] = 1e18;
	dist[0][0][2] = 0LL;
	array<int, 3> a = {0, 0, 2};
	q.insert(mp(0LL, a));
	while(!q.empty()){
		pair<ll, array<int, 3>> cur = *q.begin();
		q.erase(q.begin());
		int x = cur.se[0], y = cur.se[1];
		int nxt = (cur.se[2] + 1) % 3;
		rep(i, 4){
			int x2 = x + dx[i], y2 = y + dy[i];
			ll cst = dist[x][y][cur.se[2]] + t + (nxt == 2 ? c[x2][y2] : 0LL);
			if(valid(x2, y2) && dist[x2][y2][nxt] > cst){
				array<int, 3> b = {x2, y2, nxt};
				q.erase(mp(dist[x2][y2][nxt], b));
				dist[x2][y2][nxt] = cst;
				q.insert(mp(dist[x2][y2][nxt], b));
			}
		}
	}
	ll ans = 1e18;
	rep(i, 4) ans = min(ans, dist[n - 1][n - 1][i]);
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
