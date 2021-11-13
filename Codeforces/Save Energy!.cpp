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
const ld eps = 1e-9;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ld k, d, t;

bool check(ld g){
	ll dv = (ll)(g) / (ll)(d);
	ld ans = (ld)(dv) * ((k * 2) + d - k);
	ld rem = g - ((ld)(dv) * d);
	if(rem > k){
		ans += k * 2;
		ans += (rem - k);
	}
	else ans += rem * 2;
	if((ans + eps) >= (ld)(t * 2)) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> k >> d >> t;
	ld l = t, r = 2 * t;
	if(k > d){
		ll nm = (ll)(k + d - 1) / (ll)(d);
		d *= (ld)(nm);
	}
	rep(i, 100){
		ld mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << setprecision(10) << l << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
