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

ll dp[100005][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, p, q, r;
	cin >> n >> p >> q >> r;
	ll a[n];
	rep(i, n){
		cin >> a[i];
	}	
	dp[0][0] = p * a[0];
	repn(i, 1, n){
		dp[i][0] = max(dp[i - 1][0], p * a[i]);
	}
	dp[0][1] = dp[0][0] + q * a[0];
	repn(i, 1, n){
		dp[i][1] = max(dp[i - 1][1], dp[i][0] + q * a[i]);
	}
	dp[0][2] = dp[0][1] + r * a[0];
	repn(i, 1, n){
		dp[i][2] = max(dp[i - 1][2], dp[i][1] + r * a[i]);
	}
	cout << dp[n - 1][2] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
