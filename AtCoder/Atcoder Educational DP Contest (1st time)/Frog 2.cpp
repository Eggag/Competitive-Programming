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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int s[n];
	int dp[n];
	for(int i = 0; i < n; i++){
		cin >> s[i];
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	dp[1] = abs(s[1] - s[0]);
	for(int i = 2; i < n; i++){
		for(int p = 1; p <= k && i >= p; p++){
			dp[i] = min(dp[i], (dp[i - p] + abs(s[i - p] - s[i])));
		}
	}
	cout << dp[n - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
