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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[105][305];

void solve(){
	int n, k, l;
	cin >> n >> k >> l;
	vi d(n);
	rep(i, n) cin >> d[i];
	vi p;
	rep(i, k + 1) p.pb(i);
	for(int i = k - 1; i >= 1; i--) p.pb(i);
	rep(i, 105) rep(j, 305) dp[i][j] = 0;
	rep(i, n){
		rep(j, 2 * k){
			if((!i || (i && dp[i - 1][(j == 0 ? (2 * k) - 1 : j - 1)])) && (d[i] + p[j] <= l)){
				dp[i][j] = 1;
				repn(m, 1, 2 * k + 2){
					if(d[i] + p[(j + m) % (2 * k)] <= l){
						dp[i][(j + m) % (2 * k)] = 1;
					}
					else break;
				}
			}
		}
	}
	int f = 0;
	rep(i, 2 * k + 1) f |= dp[n - 1][i];
	if(f) cout << "Yes" << endl;
	else cout << "No" << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
