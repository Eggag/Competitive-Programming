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

ll lcm(ll a, ll b){
	return (a / gcd(a, b)) * b;
}

void solve(){
	int n;
	cin >> n;
	vector<pair<ll, int>> a(n);
	rep(i, n) cin >> a[i].fi, a[i].se = i;
	sort(all(a));
	ll cur = 0LL;
	vector<ll> ans(n, 0);
	rep(i, n - 1){
		if(cur <= 0){
			ans[a[i].se] = (a[i].fi < 0 ? -1 : 1); //add
			cur += abs(a[i].fi);
			if(i == (n - 2) && !cur){
				cur += abs(a[i].fi);
				ans[a[i].se] *= 2;
			}
		}
		else{
			ans[a[i].se] = (a[i].fi < 0 ? 1 : -1); //sub
			cur -= abs(a[i].fi);
			if(i == (n - 2) && !cur){
				cur -= abs(a[i].fi);
				ans[a[i].se] *= 2;
			}
		}
	}
	ll sgn = 1;
	if((cur < 0) == (a[n - 1].fi < 0)) sgn = -1;
	ll lc = lcm(abs(a[n - 1].fi), abs(cur));
	rep(i, n){
		if(i == a[n - 1].se) ans[i] = (lc / abs(a[n - 1].fi)) * sgn;
		else ans[i] *= lc / abs(cur);
	}
	rep(i, n) cout << ans[i] << ' ';
	cout << '\n';
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
