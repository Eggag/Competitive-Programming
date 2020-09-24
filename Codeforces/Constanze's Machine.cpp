#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	int cur = 1;
	ll ans = 1;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	rep(i, n){
		if(s[i] == 'm' || s[i] == 'w'){
			cout << 0 << endl;
			return 0;
		}
	}
	repn(i, 2, n + 1){
		dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
	}
	repn(i, 1, n){
		if(s[i] == s[i - 1] && (s[i - 1] == 'u' || s[i - 1] == 'n')){
			cur++;
		}
		else{
			if(cur > 1) ans = (dp[cur] * ans) % MOD;
			cur = 1;
		}
	}
	if(cur > 1) ans = (dp[cur] * ans) % MOD;
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
