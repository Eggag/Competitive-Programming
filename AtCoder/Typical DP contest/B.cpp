#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int w[1005], w1[1005];
int dp[1005][1005];
int sum[1005], sum1[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) cin >> w[i];
	rep(i, m) cin >> w1[i];
	reverse(w, w + n);
	reverse(w1, w1 + m);
	repn(i, 1, n + 1) sum[i] = sum[i - 1] + w[i - 1];
	repn(i, 1, m + 1) sum1[i] = sum1[i - 1] + w1[i - 1];
	dp[0][0] = 0;
	rep(i, n + 1) rep(j, m + 1) if(i + j){
		if(i) dp[i][j] = sum[i] + sum1[j] - dp[i - 1][j];
		if(j) dp[i][j] = max(dp[i][j], sum[i] + sum1[j] - dp[i][j - 1]);
	}
	cout << dp[n][m] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
