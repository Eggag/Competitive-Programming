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

ll w[405], s[405], dp[405][405];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
		s[i] = s[i - 1] + w[i];
	}
	for(int l = 2; l <= n; l++){
		for(int i = 1; i <= n - l + 1; i++){
			int j = i + l - 1;
			dp[i][j] = 1e18;
			for(int k = i; k < j; k++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
			}
		}
	}	
	cout << dp[1][n] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
