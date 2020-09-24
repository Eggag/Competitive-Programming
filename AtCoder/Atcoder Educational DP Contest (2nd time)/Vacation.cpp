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

#ifdef LOCAL
clock_t timer = clock();
#endif

int dp[100005][4];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int a[n], b[n], c[n];
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	dp[0][1] = a[0];
	dp[0][2] = b[0];
	dp[0][3] = c[0];
	for(int i = 1; i < n; i++){
		dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + a[i];
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]) + b[i];
		dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]) + c[i];
	}
	cout << max(dp[n - 1][1], max(dp[n - 1][2], dp[n - 1][3])) << endl;
#ifdef LOCAL
        cout << "Total Time: " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
