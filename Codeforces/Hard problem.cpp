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
const int maxn = 1e5 + 5;

ll dp[maxn][2];
ll c[maxn];
string s[maxn], r[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	repn(i, 1, n + 1) cin >> c[i];
	repn(i, 1, n + 1){
		cin >> s[i];
		r[i] = s[i];
		reverse(all(r[i]));
	}
	dp[1][0] = 0;
	dp[1][1] = c[1];
	repn(i, 2, n + 1){
		dp[i][0] = dp[i][1] = 1e18;
		if(s[i - 1] <= s[i]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if(s[i - 1] <= r[i]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
		if(r[i - 1] <= s[i]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		if(r[i - 1] <= r[i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
	}
	ll ans = min(dp[n][0], dp[n][1]);
	if(ans == 1e18){
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
