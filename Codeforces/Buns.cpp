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

int dp[15][1005];
int c[20], d[20];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, m, a, b;
	cin >> n >> m >> c[0] >> d[0];
	int cnt[m + 1];
	cnt[0] = n / c[0];
	for(int i = 1; i <= m; i++){
		cin >> a >> b >> c[i] >> d[i];
		cnt[i] = a / b;
	}	
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k <= cnt[i] && j + k * c[i] <= n; k++){
				dp[i + 1][j + k * c[i]] = max(dp[i + 1][j + k * c[i]], dp[i][j] + (d[i] * k));
			}
		}
	}
	cout << dp[m + 1][n] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
