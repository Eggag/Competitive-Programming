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
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 5;

ll dp[maxn][2];
ll sum[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t, k;
	cin >> t >> k;
	dp[0][0] = 1;
	repn(i, 1, maxn){
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		if(i >= k) dp[i][1] = (dp[i - k][1] + dp[i - k][0]) % MOD;
		sum[i] = (sum[i - 1] + dp[i][0] + dp[i][1]) % MOD;
	}
	while(t--){
		int a, b;
		cin >> a >> b;
		cout << (sum[b] - sum[a - 1] + MOD) % MOD << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
