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
const int MOD = 2520;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int ans[mxN][MOD], cnt[mxN][MOD];

int mod(int a, int b){
	int c = (a % b);
	return (c < 0 ? c + b : c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi k(n), sz(n);
	rep(i, n) cin >> k[i];
	rep(i, n){
		cin >> sz[i];
		g[i].resize(sz[i]);
		rep(j, sz[i]) cin >> g[i][j], g[i][j]--;
	}
	memset(cnt, -1, sizeof(cnt));
	int t = 0;
	rep(i, n) rep(j, MOD) if(!ans[i][j]){
		pi cur = mp(i, j);
		int st = t;
		vector<pi> pr;
		while(true){
			if(cnt[cur.fi][cur.se] < st && cnt[cur.fi][cur.se] >= 0){
				for(pi x : pr) ans[x.fi][x.se] = ans[cur.fi][cur.se];
				break;
			}
			if(cnt[cur.fi][cur.se] >= st){
				int ind = (int)(pr.size()) - 1;
				vi nw;
				while(pr[ind].fi != cur.fi || pr[ind].se != cur.se) nw.pb(pr[ind--].fi);
				nw.pb(cur.fi);
				sort(all(nw));
				int val = 1;
				repn(k, 1, nw.size()) if(nw[k] != nw[k - 1]) val++;
				for(pi x : pr) ans[x.fi][x.se] = val;
				break;
			}
			pr.pb(cur);
			cnt[cur.fi][cur.se] = t++;
			cur.se += k[cur.fi];
			cur.se = mod(cur.se, MOD);
			cur.fi = g[cur.fi][mod(cur.se, sz[cur.fi])];
		}
	}
	int q;
	cin >> q;
	rep(i, q){
		int x, y;
		cin >> x >> y;
		cout << ans[x - 1][mod(y, MOD)] << '\n';
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
