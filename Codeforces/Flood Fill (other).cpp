#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int dp[5005][5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[n + 1];
	repn(i, 1, n + 1) cin >> a[i];
	vi b;
	repn(i, 1, n + 1) if(i == 1 || a[i] != a[i - 1]) b.pb(a[i]);
	rep(i, 5005) rep(j, 5005) dp[i][j] = 1e9;
	rep(i, 5005) dp[i][i] = 0;
	int m = b.size();
	repn(len, 1, m) rep(l, m){
		int r = l + len;
		if(r >= m) break;
		if(b[l] == b[r] && (l + 1) < r) dp[l][r] = dp[l + 1][r - 1] + 1;
		dp[l][r] = min(dp[l][r], min(dp[l + 1][r], dp[l][r - 1]) + 1);
	}
	cout << dp[0][m - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
