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

int dp[205][205][205];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string t;
	cin >> t;
	int r = 0, g = 0, b = 0;
	for(int i = 0; i < n; i++){
		if(t[i] == 'B') b++;
		if(t[i] == 'G') g++;
		if(t[i] == 'R') r++;
	}
	dp[1][0][0] = 1; //b
	dp[0][1][0] = 2; //g
	dp[0][0][1] = 4; //r
	for(int tot = 0; tot <= 200; tot++){
		for(int i = 0; i <= 200; i++){
			for(int j = 0; j <= 200; j++){
				int k = tot - i - j;
				if(k < 0 || k > 200) continue;
				if(i >= 2) dp[i][j][k] |= dp[i - 1][j][k];
				if(j >= 2) dp[i][j][k] |= dp[i][j - 1][k];
				if(k >= 2) dp[i][j][k] |= dp[i][j][k - 1];
				if(i && j) dp[i][j][k] |= dp[i - 1][j - 1][k + 1];
				if(i && k) dp[i][j][k] |= dp[i - 1][j + 1][k - 1];
				if(j && k) dp[i][j][k] |= dp[i + 1][j - 1][k - 1]; 
			}
		}
	} 
	if(dp[b][g][r] & 1) putchar('B');
	if(dp[b][g][r] & 2) putchar('G');
	if(dp[b][g][r] & 4) putchar('R');
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
