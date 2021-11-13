#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
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

void solve(){
	ll n, k;
	cin >> n >> k;
	ll ans = 0LL;
	int len = 0;
	ll n1 = n;
	while(n1) len++, n1 /= 10;
	if(k == 1){
		ll m = 1LL;
		rep(j, len + 1){
			ans += m;
			m *= 10;
		}
	}
	else{
		ll m = 1LL;
		rep(j, len) m *= 10;
		ans = m;
	}
	string s = to_string(n);
	rep(j, 1 << 10) if(__builtin_popcount(j) == k){
		vi dig(10, 0);
		int mn = -1;
		rep(i, 10) if(j & (1 << i)){
			dig[i] = 1;
			if(mn == -1) mn = i;
		}
		rep(i, len){
			ll f = 0;
			repn(k, (int)(s[i] - '0') + 1, 10) if(dig[k]){
				f = k;
				break;
			}
			if(f){
				ll cur = 0LL, m = 1LL;
				rep(k, len){
					if(k < (len - i - 1)) cur += m * mn;
					else if(k == (len - i - 1)) cur += f * m;
					else cur += m * (ll)(s[len - k - 1] - '0');
					m *= 10;
				}
				ans = min(ans, cur);
			}
			if(!dig[s[i] - '0']) break;
			else if(i == (len - 1)) ans = n;
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
