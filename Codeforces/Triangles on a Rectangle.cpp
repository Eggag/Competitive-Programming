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
	int w, h;
	cin >> w >> h;
	ll ans = 0;
	int k1;
	cin >> k1;
	vector<ll> a(k1);
	rep(i, k1) cin >> a[i];
	ans = max(ans, (ll)(a[k1 - 1] - a[0]) * (ll)(h));
	int k2;
	cin >> k2;
	vector<ll> a1(k2);
	rep(i, k2) cin >> a1[i];
	ans = max(ans, (ll)(a1[k2 - 1] - a1[0]) * (ll)(h));
	int k3;
	cin >> k3;
	vector<ll> a2(k3);
	rep(i, k3) cin >> a2[i];
	ans = max(ans, (ll)(a2[k3 - 1] - a2[0]) * (ll)(w));
	int k4;
	cin >> k4;
	vector<ll> a3(k4);
	rep(i, k4) cin >> a3[i];
	ans = max(ans, (ll)(a3[k4 - 1] - a3[0]) * (ll)(w));
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
