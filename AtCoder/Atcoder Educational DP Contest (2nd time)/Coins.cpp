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

double dp[3005][3005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		double p;
		cin >> p;
		for(int j = 0; j < i; j++){
			dp[i][j + 1] += dp[i - 1][j] * p;
			dp[i][j] += dp[i - 1][j] * (1 - p);
		}
	}
	double res = 0.0;
	for(int i = (n / 2) + 1; i <= n; i++) res += dp[n][i];
	cout << setprecision(10) << res << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
