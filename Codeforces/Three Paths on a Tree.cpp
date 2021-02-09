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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
vi g[mxN];
array<pi, 3> lw[mxN];

bool chmax(pi a, pi b){
	if(b.fi > a.fi) return 1;
	return 0;
}

pi dfs(int cur, int prev, int f){
	array<pi, 3> mx = {mp(0, cur), mp(0, cur), mp(0, cur)};
	for(int x : g[cur]) if(x != prev){
		pi s = dfs(x, cur, f);
		s.fi++;
		if(chmax(mx[0], s)){
			mx[2] = mx[1];
			mx[1] = mx[0];
			mx[0] = s;
		}
		else if(chmax(mx[1], s)){
			mx[2] = mx[1];
			mx[1] = s;
		}
		else if(chmax(mx[2], s)) mx[2] = s;
	}
	if(f) lw[cur] = mx;
	return mx[0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	pi fs = dfs(0, -1, 0);
	pi fs1 = dfs(fs.se, -1, 1);
	int ans = fs1.fi;
	int ma = -1, bs = -1;
	rep(i, n){
		rep(j, 3) if(lw[i][j].se != fs.se && lw[i][j].se != fs1.se){
			if(lw[i][j].fi > ma){
				ma = lw[i][j].fi;
				bs = lw[i][j].se;
			}
			break;
		}
	}
	cout << ans + ma << endl;
	cout << fs.se + 1 << " " << fs1.se + 1 << " " << bs + 1 << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
