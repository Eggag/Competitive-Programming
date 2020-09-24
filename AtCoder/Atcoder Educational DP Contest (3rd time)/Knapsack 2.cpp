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

ll dp[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	ll w;
	cin >> n >> w;	
	rep(i, 100001) dp[i] = 1e18;
	dp[0] = 0;
	repn(i, 1, n + 1){
		ll a;
		int b;
		cin >> a >> b;
		for(int j = 1000 * i; j >= b; j--){
			dp[j] = min(dp[j], dp[j - b] + a);
		}
	}
	ll ans = 0;
	rep(i, 100001) if(dp[i] <= w) ans = i;
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
