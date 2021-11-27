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
	ll k, x;
	cin >> k >> x;
	ll uwu = (k * (k + 1)) / 2;
	ll tot = uwu + (k * (k - 1)) / 2;
	ll l = 1, r = k;
	if(uwu >= x){
		while(l < r){
			ll mid = (l + r + 1) / 2;
			ll owo = (mid * (mid + 1)) / 2;
			if(owo <= x) l = mid;
			else r = mid - 1;
		}
		ll pog = (l * (l + 1)) / 2;
		if(pog < x) l++;
	}
	else{
		l = k, r = 2 * k - 1;
		while(l < r){
			ll mid = (l + r + 1) / 2;
			ll ind = (2 * k - 1) - mid;
			ll lft = (ind * (ind + 1)) / 2;
			ll owo = tot - lft;
			if(owo <= x) l = mid;
			else r = mid - 1;
		}
		ll ind1 = (2 * k - 1) - l;
		ll lft1 = (ind1 * (ind1 + 1)) / 2;
		ll owo1 = tot - lft1;
		if(owo1 < x) l++;
	}
	cout << min(2 * k - 1, l) << '\n';
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
