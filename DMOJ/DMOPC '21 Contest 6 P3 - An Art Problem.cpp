#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
#define inf 0x3f3f3f3f
const int mxN = 1505;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int c[mxN][mxN];
int dist[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	memset(dist, inf, sizeof(dist));
	set<pair<int, pi>> q;
	rep(i, n) rep(j, m){
		cin >> c[i][j];
		if(c[i][j]){
			dist[i][j] = 0;
			q.insert(mp(0, mp(i, j)));
		}
	}
	while(!q.empty()){
		pair<int, pi> cr = *q.begin();
		q.erase(q.begin());
		if(cr.fi >= k) continue;
		rep(i, 4){
			int x = cr.se.fi + dx[i], y = cr.se.se + dy[i];
			if(min(x, y) >= 0 && x < n && y < m && dist[x][y]){
				if(dist[x][y] == cr.fi + 1){
					if(c[cr.se.fi][cr.se.se] < c[x][y]){
						c[x][y] = c[cr.se.fi][cr.se.se];
						q.insert(mp(dist[x][y], mp(x, y)));
					}
				}
				else if(dist[x][y] > cr.fi + 1){
					q.erase(mp(dist[x][y], mp(x, y)));
					dist[x][y] = cr.fi + 1;
					c[x][y] = c[cr.se.fi][cr.se.se];
					q.insert(mp(dist[x][y], mp(x, y)));
				}
			}
		}
	}
	rep(i, n) rep(j, m) cout << c[i][j] << " \n"[j == (m - 1)];
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
