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

int s[3005], c[3005];
int dp[5][3005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	for(int i = 0; i < n; i++){
		dp[1][i] = c[i];
		for(int j = 2; j <= 3; j++){
			dp[j][i] = 1e9;
			for(int k = 0; k < i; k++) if(s[k] < s[i]){
				dp[j][i] = min(dp[j][i], dp[j - 1][k] + c[i]);
			}
		}
	}
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		ans = min(ans, dp[3][i]);
	}
	if(ans == 1e9) ans = -1;
	cout << ans << endl;
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
