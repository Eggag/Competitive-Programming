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

int n;
int a[5005];
vi tiles;
int dp[5005][5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 1 || a[i] != a[i - 1]){
			tiles.pb(a[i]);
		}
	}
	for(int r = 0; r < tiles.size(); r++){
		for(int l = r; l >= 0; l--){
			if(l == r){
				dp[l][r] = 0;
				continue;
			}
			dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
			if(tiles[l] == tiles[r] && l + 1 < r){
				dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + 1);
			}
		}
	}
	cout << dp[0][tiles.size() - 1] << endl;	
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
