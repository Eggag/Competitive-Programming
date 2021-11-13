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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	vector<pair<ll, int>> b;
	int cnt = 1;
	repn(i, 1, n){
		if(a[i] == a[i - 1]) cnt++;
		else{
			b.pb(mp(a[i - 1], cnt));
			cnt = 1;
		}
	}
	b.pb(mp(a[n - 1], cnt));
	ll sum = 0, num = 0;
	ll tot = 0, num1 = n;
	ll ans = 1e18;
	rep(i, b.size()) tot += (b[i].fi * (ll)(b[i].se));
	rep(i, b.size()){
		tot -= (b[i].fi * (ll)(b[i].se));
		num1 -= b[i].se;
		int cur = b[i].se;
		if(cur >= k){
			ans = 0;
			break;
		}
		int need = k - cur;
		ll lw = ((b[i].fi - 1) * num) - sum;
		ll up = tot - ((b[i].fi + 1) * num1);
		int f = 0;
		if(num >= need) f |= 1;
		if(num1 >= need) f |= 2;
		if(f == 3) ans = min(ans, min(up, lw) + (ll)(need));
		if(f == 2) ans = min(ans, up + (ll)(need));
		if(f == 1) ans = min(ans, lw + (ll)(need));
		if(!f && (num + num1) >= need) ans = min(ans, lw + up + (ll)(need));
		num += (ll)(b[i].se);
		sum += (b[i].fi * (ll)(b[i].se));
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
