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

int dp[1005][1005];
char g[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	repn(i, 1, h + 1) repn(j, 1, w + 1){
		cin >> g[i][j];
	}
	dp[1][1] = 1;
	repn(i, 1, h + 1) repn(j, 1, w + 1){
		if(g[i][j] == '#'){
			dp[i][j] = 0;
			continue;
		}
		if((i - 1) && g[i - 1][j] == '.') dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
		if((j - 1) && g[i][j - 1] == '.') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
	}
	cout << dp[h][w] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
