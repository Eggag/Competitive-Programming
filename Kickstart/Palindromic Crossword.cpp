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
const int mxN = 1005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

string s[mxN];
pi g[mxN][mxN], h[mxN][mxN];

void solve(){
	int n, m;
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	rep(i, n){
		int l = -1;
		rep(j, m){
			if(s[i][j] != '#'){
				if(l == -1) l = j;
			}
			else{
				if(l != -1) repn(k, l, j) g[i][k] = mp(l, j - 1);
				l = -1;
			}
		}
		if(l != -1) repn(k, l, m) g[i][k] = mp(l, m - 1);
	}
	rep(j, m){
		int l = -1;
		rep(i, n){
			if(s[i][j] != '#'){
				if(l == -1) l = i;
			}
			else{
				if(l != -1) repn(k, l, i) h[k][j] = mp(l, i - 1);
				l = -1;
			}
		}
		if(l != -1) repn(k, l, n) h[k][j] = mp(l, n - 1);
	}
	queue<pi> q;
	int ans = 0;
	rep(i, n) rep(j, m) if(s[i][j] >= 'A' && s[i][j] <= 'Z') q.push(mp(i, j));
	while(!q.empty()){
		pi cr = q.front();
		q.pop();
		//horizontal
		int le = g[cr.fi][cr.se].fi, ri = g[cr.fi][cr.se].se;
		int nx = le + (ri - cr.se);
		if(s[cr.fi][nx] == '.'){
			s[cr.fi][nx] = s[cr.fi][cr.se];
			ans++;
			q.push(mp(cr.fi, nx));
		}
		//vertical
		le = h[cr.fi][cr.se].fi, ri = h[cr.fi][cr.se].se;
		nx = le + (ri - cr.fi);
		if(s[nx][cr.se] == '.'){
			s[nx][cr.se] = s[cr.fi][cr.se];
			ans++;
			q.push(mp(nx, cr.se));
		}
	}
	cout << ans << '\n';
	rep(i, n){
		rep(j, m) cout << s[i][j];
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
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
