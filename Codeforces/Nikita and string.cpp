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

int dp[5005][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.length();
	repn(i, 1, n + 1){
		rep(j, 3) dp[i][j] = dp[i - 1][j];
		if(s[i - 1] == 'a'){
			dp[i][0]++;
			dp[i][1] = max(dp[i][0], dp[i][1]);
			dp[i][2] = max(dp[i][1], max(dp[i - 1][1] + 1, dp[i][2] + 1));
		}
		else{
			dp[i][1] = max(dp[i][1] + 1, dp[i - 1][0] + 1);
			dp[i][2] = max(dp[i][2], dp[i][1]);
		}
	}
	cout << dp[n][2] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
