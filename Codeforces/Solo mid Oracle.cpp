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

ll a, b, c, d;

ll f(ll nm){
	ll val = 0LL;
	ll div = c / d;
	if((nm - 1) < div) val = d * ((nm * (nm - 1)) / 2);
	else{
		val = d * ((div * (div + 1)) / 2);
		val += c * (nm - div - 1);
	}
	return (ll)(1LL * nm * a) - (b * val);
}

void solve(){
	cin >> a >> b >> c >> d;
	if(a > (c * b)){
		cout << -1 << '\n';
		return;
	}
	ll l = 1LL, r = 1e6 + 1;
	while((r - l) > 100){
		ll mid = (l + r) / 2;
		if(f(mid) > f(mid + 1)) r = mid;
		else l = mid;
	}
	ll mx = 0LL;
	repn(i, l, r + 1) mx = max(mx, f(i));
	cout << mx << '\n';
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
