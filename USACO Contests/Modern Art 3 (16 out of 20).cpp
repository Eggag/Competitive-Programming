#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sq(x) ((x) * (x))
#define inf 0x3f3f3f3f
const int mxN = 305;

int dp[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vi b(n);
	rep(i, n) cin >> b[i];
	vi a = {b[0]};
	repn(i, 1, n) if(b[i] != b[i - 1]) a.pb(b[i]);
	memset(dp, inf, sizeof(dp));
	n = a.size();
	rep(i, n) dp[i][i] = 1;
	repn(len, 1, n){
		rep(i, n - len){
			int l = i, r = i + len;
			if(a[l] == a[r]) dp[l][r] = 1 + (len > 1 ? dp[l + 1][r - 1] : 0);
			vi dp1(n, inf);
			dp1[l] = 1;
			vi lst(100, -1);
			lst[0] = l;
			repn(j, l + 1, r){
				if(a[j] == a[l]){
					rep(k, 100) if(lst[k] != -1){
						dp1[j] = min(dp1[j], dp1[lst[k]] + dp[lst[k] + 1][j - 1]);
					}
					repn(k, 1, 100) lst[k] = lst[k - 1];
					lst[0] = j;
				}
			}
			rep(k, 100) if(lst[k] != -1){
				dp1[r] = min(dp1[r], dp1[lst[k]] + dp[lst[k] + 1][r - (a[r] == a[l])]);
			}
			dp[l][r] = min(dp[l][r], dp1[r]);
			repn(x, l, r){
				int f = 0;
				if(a[l] == a[x] && a[r] == a[l] && x != l && x != (r - 1)) f = 1;
				if(f) dp[l][r] = min(dp[l][r], dp[l + 1][x - 1] + dp[x + 1][r - 1] + 1);
				dp[l][r] = min(dp[l][r], dp[l][x] + dp[x + 1][r]);

			}
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
