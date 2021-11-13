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
	ll l, r, m;
	cin >> l >> r >> m;
	for(ll a = l; a <= r; a++){
		ll cr = m - ((m / a) * a);
		ll b = l + cr, c = l;
		if(cr <= (r - l) && ((m - (b - c)) / a) > 0){
			assert((m - (b - c)) % a == 0);
			cout << a << " " << b << " " << c << '\n';
			return;
		}
	}
	for(ll a = l; a <= r; a++){
		ll cr = m - (((m + a - 1) / a) * a);
		ll b = l + cr, c = l;
		if(cr < 0){
			b = l, c = l - cr;
			cr = -cr;
		}
		if(cr <= (r - l) && ((m - (b - c)) / a) > 0){
			assert((m - (b - c)) % a == 0);
			cout << a << " " << b << " " << c << '\n';
			return;
		}
	}
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
