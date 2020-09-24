#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int h, w;
string g[1005];
int dp[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		cin >> g[i];
	}
	ll MOD = 1e9 + 7;
	dp[0][0] = 1;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(i > 0 && g[i - 1][j] == '.') dp[i][j] = (dp[i - 1][j] + dp[i][j]) % MOD;
			if(j > 0 && g[i][j - 1] == '.') dp[i][j] = (dp[i][j - 1] + dp[i][j]) % MOD;
			if(g[i][j] == '#') dp[i][j] = 0;
		}
	}
	cout << dp[h - 1][w - 1] << endl;	
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

