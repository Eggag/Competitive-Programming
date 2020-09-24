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
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
ll dp[1000005];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	if(m <= 1e6){
		dp[0] = 1;
		rep(i, n) for(ll j = m - a[i]; j >= 0; j--) dp[j + a[i]] += dp[j]; 
		ll ans = 0;
		rep(i, 1000005) ans += dp[i];
		cout << ans << endl;
	}
	else{
		int ans = 0;
		rep(i, (1 << n)){
			ll tot = 0;
			rep(j, n) if(i & (1 << j)) tot += a[j];
			if(tot <= m) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/