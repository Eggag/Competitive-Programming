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
const int mxN = 1005;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
int dist[3][mxN][mxN];

bool valid(int i, int j){
	return(i >= 0 && j >= 0 && i < n && j < m);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int ans = inf;
	memset(dist, inf, sizeof(dist));
	deque<pi> q;
	rep(i, 3){
		rep(j, n) rep(k, m) if(s[j][k] == (char)('1' + i)){
			dist[i][j][k] = 0;
			q.pb(mp(j, k));
		}
		while(!q.empty()){
			pi cr = q.front();
			q.pop_front();
			rep(j, 4){
				int x = cr.fi + dx[j], y = cr.se + dy[j];
				if(valid(x, y) && s[x][y] != '#'){
					if(dist[i][x][y] > dist[i][cr.fi][cr.se] + (s[x][y] == '.')){
						dist[i][x][y] = dist[i][cr.fi][cr.se] + (s[x][y] == '.');
						if(s[x][y] == '.') q.pb(mp(x, y));
						else q.push_front(mp(x, y));
					}
				}
			}
		}
	}
	rep(i, n) rep(j, m) if(max({dist[0][i][j], dist[1][i][j], dist[2][i][j]}) < inf){
		int cur = 0;
		rep(k, 3) cur += dist[k][i][j];
		if(s[i][j] == '.') cur -= 2;
		ans = min(ans, cur);
	}
	cout << (ans == inf ? -1 : ans) << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
