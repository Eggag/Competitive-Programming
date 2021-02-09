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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll hsh[15][mxN];
ll pows[mxN];
ll p[15][mxN];
int pos[15][mxN];
ll MOD = 1e9 + 7;

ll comp_hs(int l, int r, int ind){
	l++, r++;
	ll h1 = (((hsh[ind][r] - hsh[ind][l - 1] * pows[(r - l + 1)]) % MOD) + MOD) % MOD;
	return h1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, m) rep(j, n) cin >> p[i][j], pos[i][p[i][j]] = j;
	pows[0] = 1;	
	for(int i = 1; i <= n; i++){
		pows[i] = (pows[i - 1] * 697049) % MOD;
	}
	rep(j, m){
		for(int i = 1; i <= n; i++){
			hsh[j][i] = (hsh[j][i - 1] * 697049) + (ll)(p[j][i - 1]) + 1;
			hsh[j][i] %= MOD;
		}
	}
	ll ans = 0LL;
	repn(i, 1, n + 1){
		int mx = 0;
		rep(j, m) mx = max(mx, pos[j][i]);
		int l = 0, r = n - mx - 1;
		while(l < r){
			int mid = (l + r + 1) / 2;
			ll fs = 0LL;
			rep(j, m){
				ll cur = comp_hs(pos[j][i], pos[j][i] + mid, j);
				if(!j) fs = cur;
				if(cur != fs){
					r = mid - 1;
					goto en;
				}
			}
			l = mid;
			en:;
		}
		ans += l + 1;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
