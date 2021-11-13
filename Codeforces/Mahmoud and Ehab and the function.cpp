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
	int n, m, q;
	cin >> n >> m >> q;
	vector<ll> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	vector<ll> pr;
	vector<ll> e(m, 0LL), o(m, 0LL);
	e[0] = b[0];
	repn(i, 1, m){
		e[i] = e[i - 1];
		o[i] = o[i - 1];
		if(i % 2 == 0) e[i] += b[i];
		else o[i] += b[i];
	}
	rep(i, m - n + 1){
		ll ee = e[i + n - 1] - (i ? e[i - 1] : 0LL);
		ll oo = o[i + n - 1] - (i ? o[i - 1] : 0LL);
		if(i % 2 == 0) pr.pb(ee - oo);
		else pr.pb(oo - ee);
	}
	sort(all(pr));
	ll ev = 0LL, od = 0LL;
	rep(i, n){
		if(i % 2 == 0) ev += a[i];
		else od += a[i];
	}
	rep(i, q + 1){
		ll df = ev - od;
		auto it = lb(all(pr), df);
		ll ans = 1e18;
		if(it != pr.end()){
			ans = abs(df - *it);
		}
		if(it != pr.begin()){
			it--;
			ans = min(ans, abs(df - *it));
		}
		cout << ans << '\n';
		if(i == q) break;
		int l, r;
		ll x;
		cin >> l >> r >> x;
		l--, r--;
		ll add = (r - l + 1) / 2;
		ev += x * add;
		od += x * add;
		if((r - l + 1) & 1){
			if(l & 1) od += x;
			else ev += x;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
