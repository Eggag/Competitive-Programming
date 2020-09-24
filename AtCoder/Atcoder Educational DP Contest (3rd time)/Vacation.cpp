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

int dp[100005][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	rep(i, n){
		cin >> a[i] >> b[i] >> c[i];
	}
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = c[0];
	repn(i, 1, n){
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
	}
	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
