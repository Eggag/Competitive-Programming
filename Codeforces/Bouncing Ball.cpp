#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
	ll n, p, k;
	cin >> n >> p >> k;
	string s;
	cin >> s;
	vi a(n + 1);
	repn(i, 1, n + 1) a[i] = (s[i - 1] == '1');
	ll x, y;
	cin >> x >> y;
	ll ans = 1e18;
	vector<ll> cnt(k, 0);
	repn(i, p, n + 1) if(!a[i]) cnt[i % k]++;
	rep(i, n + 1){
		if((p + i) > n) break;
		ll cur = (ll)(1LL * i * y);
		ll nm = cnt[(p + i) % k];
		cur += (ll)(nm * x);
		ans = min(ans, cur);
		if(!a[p + i]) cnt[(p + i) % k]--;
	}
	cout << ans << endl;
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
