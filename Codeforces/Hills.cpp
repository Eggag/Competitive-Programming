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
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][mxN];
int mn[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	rep(i, mxN) rep(j, mxN) dp[i][j] = 1e9;
	rep(i, mxN) mn[i] = 1e9;
	mn[0] = 0;
	rep(i, mxN) dp[i][0] = 0;
	dp[0][1] = max(0, a[1] - a[0] + 1);
	repn(i, 1, n){
		dp[i][1] = max(0, a[i - 1] - a[i] + 1) + ((i < (n - 1)) ? max(a[i + 1] - a[i] + 1, 0) : 0);
		if(i > 1){
			repn(j, 2, ((n + 1) / 2) + 1){
				int nw = min(a[i - 1], a[i - 2] - 1);
				dp[i][j] = min(dp[i][j], dp[i - 2][j - 1] + ((i < (n - 1)) ? max(0, a[i + 1] - a[i] + 1) : 0) + max(0, nw - a[i] + 1));
			}	
		}
		if(i > 1){
			repn(j, 1, ((n + 1) / 2) + 1){
				dp[i][j] = min(mn[j - 1] + max(0, a[i - 1] - a[i] + 1) + (i < (n - 1) ? max(a[i + 1] - a[i] + 1, 0) : 0), dp[i][j]);
			}
			repn(j, 1, ((n + 1) / 2) + 1){
				if(i > 1) mn[j] = min(mn[j], dp[i - 2][j]);
			}
		}
	}
	vi ans(((n + 1) / 2) + 1, 1e9);
	rep(i, n){
		repn(j, 1, ((n + 1) / 2) + 1){
			ans[j] = min(ans[j], dp[i][j]);
		}
	}
	repn(i, 1, ((n + 1) / 2) + 1) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
