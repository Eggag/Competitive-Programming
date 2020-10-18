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
const int mxN = 52;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN][mxN][mxN][mxN];
int ans = 1;

void chmax(int &a, int b){
	a = max(a, b);
	ans = max(ans, a);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("subrev.in", "r", stdin);
	freopen("subrev.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	memset(dp, 0, sizeof(dp));
	rep(i, n) dp[i][i][a[i]][a[i]] = 1;
	rep(i, n - 1) dp[i][i + 1][min(a[i], a[i + 1])][max(a[i], a[i + 1])] = 2;
	repn(len, 1, n){
		rep(i, n - len + 1) repn(mn, 1, 51) repn(mx, mn, 51) if(dp[i][i + len - 1][mn][mx]){
			//we only expand to the left
			int r = i + len - 1;
			int cr = dp[i][r][mn][mx];
			if(i){
				chmax(dp[i - 1][r][mn][mx], cr);
				if(a[i - 1] <= mn) chmax(dp[i - 1][r][a[i - 1]][mx], cr + 1);
			}
			//we only expand to the right
			if(r < (n - 1)){
				chmax(dp[i][r + 1][mn][mx], cr);
				if(a[r + 1] >= mx) chmax(dp[i][r + 1][mn][a[r + 1]], cr + 1);
			}
			//we expand both to the left and right (for this one we try to swap)
			if(i && (r < (n - 1))){
				chmax(dp[i - 1][r + 1][mn][mx], cr);
				if(a[i - 1] <= mn && a[r + 1] >= mx){
					chmax(dp[i - 1][r + 1][a[i - 1]][a[r + 1]], cr + 2);
				}
				swap(a[i - 1], a[r + 1]);
				if(a[i - 1] <= mn && a[r + 1] >= mx){
					chmax(dp[i - 1][r + 1][a[i - 1]][a[r + 1]], cr + 2);
				}
				if(i){
					chmax(dp[i - 1][r + 1][mn][mx], cr);
					if(a[i - 1] <= mn) chmax(dp[i - 1][r + 1][a[i - 1]][mx], cr + 1);
				}
				//we only expand to the right
				if(r < (n - 1)){
					chmax(dp[i - 1][r + 1][mn][mx], cr);
					if(a[r + 1] >= mx) chmax(dp[i - 1][r + 1][mn][a[r + 1]], cr + 1);
				}
				swap(a[i - 1], a[r + 1]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
