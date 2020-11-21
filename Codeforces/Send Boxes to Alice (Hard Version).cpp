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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0LL;
	rep(i, n) cin >> a[i], sum += a[i];
	vector<ll> p;
	for(ll i = 2; (i * i) <= sum; i++){
		if(sum % i == 0) p.pb(i);
		while(sum % i == 0) sum /= i;
	}
	if(sum > 1) p.pb(sum);
	if(!p.size()){
		cout << -1 << endl;
		return 0;
	}
	ll ans = 1e18;
	rep(k, p.size()){
		ll num = p[k];
		vector<ll> b(n), c(n);
		rep(i, n) b[i] = a[i] % num;
		c[0] = b[0];
		ll cur = 0LL, seg = 0LL;
		int l = 0;
		rep(i, n){
			ll df = num - seg;
			seg += b[i];
			if(seg >= num){
				ll mn = 1e18;
				ll le = 0LL, ri = 0LL, tot = 0LL;
				c[i] = df;
				for(int j = i; j >= l; j--){
					tot += ri;
					if(j == l || j == i) ri += c[j];
					else ri += b[j];
				}
				repn(j, l, i + 1){
					mn = min(mn, tot);
					if(j != l && j != i) ri -= b[j];
					else ri -= c[j];
					tot -= ri;
					if(j != l && j != i) le += b[j];
					else le += c[j];
					tot += le;
				}
				cur += mn;
				c[i] = seg - num;
				l = i;
				seg = seg - num;
			}
		}
		assert(!seg);
		ans = min(ans, cur);
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
