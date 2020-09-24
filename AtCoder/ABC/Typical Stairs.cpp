#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
const int MOD = 1e9 + 7;

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[100005];
int s[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[m];
	memset(s, 0, sizeof(s));
	rep(i, m) cin >> a[i], s[a[i]] = 1;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	repn(i, 0, n){
		repn(j, 1, 3){
			if(i + j <= n && !s[i + j]){
				dp[i + j] = (dp[i + j] + dp[i]) % MOD;
			}
		}
	}
	cout << dp[n] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
