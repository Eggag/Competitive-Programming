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

void solve(){
	int n;
	cin >> n;
	vector<pair<ll, ll>> p(n);
	rep(i, n) cin >> p[i].fi;
	rep(i, n) cin >> p[i].se;
	sort(all(p));
	ll ans = 0LL;
	pair<ll, ll> pr = {1, 1};
	rep(i, n){
		if(p[i] == pr) continue;
		ll dx = p[i].fi - pr.fi, dy = p[i].se - pr.se;
		assert(dy <= dx && dy >= 0);
		if((pr.fi + pr.se) % 2 == 0){
			if(dy == dx) ans += dx;
			else ans += (dx - dy) / 2;
		}
		else{
			ans += (dx - dy + 1) / 2;
		}
		pr = p[i];
	}
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
