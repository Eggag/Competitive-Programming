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

int dp[4005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, a , b, c;
	cin >> n >> a >> b >> c;
	dp[a] = dp[b] = dp[c] = 1;
	for(int i = 1; i <= n; i++){
		if(i - a >= 0 && dp[i - a]) dp[i] = max(dp[i], dp[i - a] + 1);
		if(i - b >= 0 && dp[i - b]) dp[i] = max(dp[i], dp[i - b] + 1);
		if(i - c >= 0 && dp[i - c]) dp[i] = max(dp[i], dp[i - c] + 1);
	}
	cout << dp[n] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
