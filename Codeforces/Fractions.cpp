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

set<pair<ll, ll>> st;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	for(ll i = 1LL; i <= 998; i++) for(ll j = 1LL; j <= 998; j++){
		ll i1 = i, j1 = j;
		ll g = gcd(i1, j1);
		i1 /= g;
		j1 /= g;
		if((i + j) < 1000) st.insert(mp(i1, j1));
	}
	//Awesome problem!!!
	ll ans = 0;
	for(pair<ll, ll> x : st){
		//cout << "--------" << endl;
		ll xse = x.se;
		ll xfi = x.fi;
		ll num = 1, num1 = 1;
		if(xfi < a) num = (a + xfi - 1) / xfi;
		if(xse < c) num1 = (c + xse - 1) / xse;
		xfi *= max(num, num1);
		xse *= max(num, num1);
		if(xfi > b || xse > d) continue;
		//assert((xfi >= a && xfi <= b) && (xse >= c && xse <= d));
		//debug2(x.fi, x.se);
		//debug2(xfi, xse);
		ll num2 = b / x.fi;
		ll num3 = d / x.se;
		//debug2(num2, num3);
		//debug2(min(num2, num3) * x.fi, min(num2, num3) * x.se);
		ll cur = 1 + (min(num2, num3) - (xfi / x.fi));
		//debug(cur);
		ans += cur;
	}
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
