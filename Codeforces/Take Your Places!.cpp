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
	int n;
	cin >> n;
	vi od, ev;
	int o = 0, e = 0;
	rep(i, n){
		int a;
		cin >> a;
		if(a & 1) od.pb(i);
		else ev.pb(i);
		if(i & 1) o++;
		else e++;
	}
	ll ans = 1e18;
	if(o == (int)(od.size())){
		int x = 0;
		ll cur = 0;
		rep(i, n) if(i & 1) cur += abs(i - od[x++]);
		ans = min(ans, cur);
	}
	if(e == (int)(od.size())){
		int x = 0;
		ll cur = 0;
		rep(i, n) if(i % 2 == 0) cur += abs(i - od[x++]);
		ans = min(ans, cur);
	}
	cout << (ans == 1e18 ? -1 : ans) << '\n';
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
