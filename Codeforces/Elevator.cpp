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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[2][11][11][11][11];

void chmin(int &a, int b){
	a = min(a, b);
}

int f(int a, int b, int c){
	if(a >= min(b, c) && a <= max(b, c)) return 0;
	return a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	int ans = 2 * n;
	memset(dp, inf, sizeof(dp));
	dp[0][0][0][0][0] = ans;
	rep(i, n + 1){
		int pr = i & 1, cr = 1 - pr;
		rep(j, 10) repn(k, j, 10) repn(l, k, 10) repn(m, l, 10) if(dp[pr][j][k][l][m] != inf){
			int pos = (i ? p[i - 1].fi : 1);
			array<int, 4> a = {j, k, l, m};
			sort(all(a));
			rep(ff, (1 << 4)){
				vi uwu;
				int d = 0;
				rep(g, 4) if((ff & (1 << g)) && a[g]) uwu.pb(a[g]);
				int le = pos, r = pos;
				if(!uwu.size()) d = (i == n ? 0 : abs(pos - p[i].fi));
				else{
					rep(x, uwu.size()) le = min(uwu[x], le), r = max(uwu[x], r);
					d = (pos - le) + (r - le) + (i == n ? 0 : abs(r - p[i].fi));
					d = min(d, (r - pos) + (r - le) + (i == n ? 0 : abs(le - p[i].fi)));
				}
				if(i != n) le = min(le, p[i].fi), r = max(r, p[i].fi);
				array<int, 4> b = {f(j, le, r), f(k, le, r), f(l, le, r), f(m, le, r)};
				if(i != n){
					int fk = 0;
					rep(g, 4) if(!b[g]){
						b[g] = p[i].se;
						fk = 1;
						break;
					}
					if(!fk) continue;
				}
				sort(all(b));
				chmin(dp[cr][b[0]][b[1]][b[2]][b[3]], dp[pr][j][k][l][m] + d);
			}
		}
		memset(dp[pr], inf, sizeof(dp[pr]));
	}
	cout << dp[(n + 1) & 1][0][0][0][0] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
