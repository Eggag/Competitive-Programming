#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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

int dp[1005][5005];
vi box[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi a(m + 1), b(m + 1);
	repn(i, 1, m + 1){
		cin >> a[i] >> b[i];
		rep(j, b[i]){
			int x;
			cin >> x;
			x--;
			box[i].pb(x);
		}
	}
	rep(i, 1005) rep(j, 5005) dp[i][j] = 1e9;
	dp[0][0] = 0;
	repn(i, 1, m + 1){
		rep(j, (1 << n)) dp[i][j] = dp[i - 1][j];
		rep(j, (1 << n)){
			int cur = j;
			rep(k, box[i].size()) cur |= (1 << box[i][k]);
			dp[i][cur] = min({dp[i - 1][cur], dp[i - 1][j] + a[i], dp[i][cur]});
		}
	}
	if(dp[m][(1 << n) - 1] == 1e9) cout << -1 << endl;
	else cout << dp[m][(1 << n) - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
