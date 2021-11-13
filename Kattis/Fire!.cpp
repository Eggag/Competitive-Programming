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
const int dy[4] = {0, 0, -1, 1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int d1[mxN][mxN];
int d2[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	queue<pi> q;
	memset(d1, inf, sizeof(d1));
	memset(d2, inf, sizeof(d2));
	rep(i, n) rep(j, m){
		if(s[i][j] == 'J'){
			d1[i][j] = 1;
			q.push(mp(i, j));
		}
	}
	while(!q.empty()){
		pi cr = q.front();
		q.pop();
		rep(i, 4){
			int x = dx[i] + cr.fi, y = dy[i] + cr.se;
			if(x >= 0 && y >= 0 && x < n && y < m && d1[x][y] == inf && s[x][y] != '#'){
				d1[x][y] = 1 + d1[cr.fi][cr.se];
				q.push(mp(x, y));
			}
		}
	}
	rep(i, n) rep(j, m){
		if(s[i][j] == 'F'){
			d2[i][j] = 1;
			q.push(mp(i, j));
		}
	}
	while(!q.empty()){
		pi cr = q.front();
		q.pop();
		rep(i, 4){
			int x = dx[i] + cr.fi, y = dy[i] + cr.se;
			if(x >= 0 && y >= 0 && x < n && y < m && d2[x][y] == inf && s[x][y] != '#'){
				d2[x][y] = 1 + d2[cr.fi][cr.se];
				q.push(mp(x, y));
			}
		}
	}
	int ans = 1e9;
	rep(i, n){
		if(s[i][0] != '#' && d1[i][0] < d2[i][0]) ans = min(ans, d1[i][0]);
		if(s[i][m - 1] != '#' && d1[i][m - 1] < d2[i][m - 1]) ans = min(ans, d1[i][m - 1]);
	}
	rep(i, m){
		if(s[0][i] != '#' && d1[0][i] < d2[0][i]) ans = min(ans, d1[0][i]);
		if(s[n - 1][i] != '#' && d1[n - 1][i] < d2[n - 1][i]) ans = min(ans, d1[n - 1][i]);
	}
	if(ans == 1e9) cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
