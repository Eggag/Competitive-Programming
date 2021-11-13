#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define debug(x) cerr << #x << " " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define all(v) v.begin, v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int mxN = 505;

int dp[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, d, T;
	cin >> n >> d >> T;
	vi t(n);
	rep(i, n) cin >> t[i];
	if(n <= 500){
		rep(i, n){
			if(!i){
				int sv = 0;
				int mn = 1e9;
				repn(j, i, n){
					mn = min(mn, t[j] - j);
					if((mn + j) > T) sv++;
					dp[j][0] = max(dp[j][0], sv);
				}
				continue;
			}
			rep(j, d){
				int sv = dp[i - 1][j];
				int mn = 1e9;
				repn(k, i, n){
					mn = min(mn, t[k] - k);
					if((mn + k) > T) sv++;
					dp[k][j + 1] = max(dp[k][j + 1], sv);
				}
			}
		}
		int ans = 0;
		rep(j, d + 1) ans = max(ans, dp[n - 1][j]);
		cout << n - ans << '\n';
	}
}
