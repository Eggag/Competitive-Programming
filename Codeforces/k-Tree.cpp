#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
const int MOD = 1e9 + 7;

ll dp[105][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k, d;
	cin >> n >> k >> d;
	dp[0][0] = 1;
	dp[0][1] = 0;
	repn(i, 1, n + 1){
		dp[i][0] = dp[i][1] = 0;
		repn(j, 1, k + 1){
			if(i - j < 0) break;
			if(j >= d){
				dp[i][1] = (dp[i][1] + dp[i - j][1] + dp[i - j][0]) % MOD;
			}
			else{
				dp[i][1] = (dp[i][1] + dp[i - j][1]) % MOD;	
				dp[i][0] = (dp[i][0] + dp[i - j][0]) % MOD;
			}
		}
	}
	cout << dp[n][1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
