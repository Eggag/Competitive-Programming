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

string w[55];
int dp[55][55];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	int k = w[1].length();
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < k; j++){
			dp[i][j] = 1e9;
		}
	}
	for(int i = 1; i <= n; i++){
		w[i] += w[i];
	}
	for(int i = 0; i < k; i++){
		dp[1][i] = i;
	}
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < k; j++){
			for(int p = 0; p < k; p++){
				if(w[i].substr(j, k) == w[i - 1].substr(p, k)){
					dp[i][j] = min(dp[i][j], dp[i - 1][p] + j);
				}
			}
		}
	}
	int ans = 1e9;
	for(int i = 0; i < k; i++){
		ans = min(ans, dp[n][i]);
	}
	if(ans == 1e9){
		cout << "-1" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
