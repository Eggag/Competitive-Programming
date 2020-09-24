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

ll dp[100100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, w;
	cin >> n >> w;	
	int a[n], b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = w - a[i]; j >= 0; j--){
			dp[j + a[i]] = max(dp[j] + b[i], dp[j + a[i]]);
		}
	}
	ll ans = 0;
	for(int i = 0; i <= w; i++){
		ans = max(ans, dp[i]);
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
