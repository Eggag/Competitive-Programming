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
const int MAXN = 1e5 + 5;

ll sum[MAXN];
ll dp[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t, k;
	cin >> t >> k;
	dp[0] = 1;
	repn(i, 1, MAXN){
		dp[i] = dp[i - 1] % MOD;
		if(i >= k) dp[i] = (dp[i] + dp[i - k]) % MOD;
		sum[i] = (sum[i - 1] + dp[i]) % MOD;
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
