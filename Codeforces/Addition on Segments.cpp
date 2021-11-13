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
const int MOD = 1e9 + 7;
const int mxN = 1e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[mxN];
int pos[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<pi> ev;
	rep(i, q){
		int l, r, x;
		cin >> l >> r >> x;
		l--, r--;
		ev.pb(mp(l, x));
		ev.pb(mp(r + 1, -x));
	}
	sort(all(ev));
	dp[0] = 1;
	rep(i, 2 * q){
		if(ev[i].se > 0){
			for(int j = n - ev[i].se; j >= 0; j--){
				dp[j + ev[i].se] += dp[j];
				if(dp[j + ev[i].se] >= MOD) dp[j + ev[i].se] -= MOD;
			}
		}
		else{
			ev[i].se *= -1;
			for(int j = ev[i].se; j <= n; j++){
				dp[j] -= dp[j - ev[i].se];
				if(dp[j] < 0) dp[j] += MOD;
			}
		}
		repn(j, 1, n + 1) if(dp[j]) pos[j] = 1;
	}
	vi ans;
	repn(i, 1, n + 1) if(pos[i]) ans.pb(i);
	cout << (int)(ans.size()) << '\n';
	for(int x : ans) cout << x << ' ';
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
