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

int dp[100][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	repn(i, 1, n + 1){
		cin >> a[i];
	}
	repn(i, 1, n + 1){
		dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
		if(a[i] & 1) dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		else dp[i][1] = 1e9;
		if(a[i] & 2) dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]);
		else dp[i][2] = 1e9;
	}
	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
