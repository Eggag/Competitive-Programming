#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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

ll solve(ll a, ll b){
	vector<ll> pos;
	for(ll j = 1; (j * j) <= a; j++){
		if(a % j == 0){
			pos.pb(j);
			if(j != a / j) pos.pb(a / j);
		}	
	}
	sort(all(pos));
	ll ans = 1e18;
	for(ll j = 1; (j * j) <= (a + b); j++){
		if((a + b) % j == 0){
			ll bg = max(j, (a + b) / j);
			ll sm = min(j, (a + b) / j);
			auto it = ub(all(pos), bg);
			if(it == pos.end()) it--;
			if(*it > bg) it--;
			if(sm >= a / *it) ans = min(ans, 2 * j + 2 * ((a + b) / j));
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll a, b;
	cin >> a >> b;
	ll ans = solve(a, b);
	ans = min(ans, solve(b, a));
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
