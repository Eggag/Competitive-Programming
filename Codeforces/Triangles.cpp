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
const int mxN = 2005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

char s[mxN][mxN];
char s1[mxN][mxN];

void solve(){
	int n;
	cin >> n;
	rep(i, n) rep(j, n) cin >> s[i][j];
	vi res(10, 0);
	rep(d, 10){
		int ans = 0;
		char c = (char)('0' + d);
		int mn = 1e9, mx = -1e9;
		rep(i, n) rep(j, n) if(s[i][j] == c) mn = min(mn, i), mx = max(mx, i);
		rep(i, n){
			int a = 1e9, b = -1e9;
			rep(j, n) if(s[i][j] == c) a = min(a, j), b = max(b, j);
			if(a != 1e9){
				int len = max(n - a - 1, b);
				ans = max(ans, (b - a) * max((n - 1) - i, i));
				ans = max(ans, len * max(mx - i, i - mn));
			}
		}
		res[d] = ans;
	}
	rep(i, n) rep(j, n) s1[j][n - 1 - i] = s[i][j];
	rep(d, 10){
		int ans = 0;
		char c = (char)('0' + d);
		int mn = 1e9, mx = -1e9;
		rep(i, n) rep(j, n) if(s1[i][j] == c) mn = min(mn, i), mx = max(mx, i);
		rep(i, n){
			int a = 1e9, b = -1e9;
			rep(j, n) if(s1[i][j] == c) a = min(a, j), b = max(b, j);
			if(a != 1e9){
				int len = max(n - a - 1, b);
				ans = max(ans, (b - a) * max((n - 1) - i, i));
				ans = max(ans, len * max(mx - i, i - mn));
			}
		}
		res[d] = max(res[d], ans);
	}
	rep(i, 10) cout << res[i] << " ";
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
