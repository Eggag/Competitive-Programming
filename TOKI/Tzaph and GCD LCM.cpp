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
	ll g, l;
	cin >> g >> l;
	//l = (a * b) / g
	//(a * b) = l * g
	//they are composed of the divisors of l and g
	//and we want to distribute the divisors of l/g
	//so that a and b are as close as possible
	//we can do a bitmask over those
	if(l % g == 0){
		vector<ll> pr;
		ll nm = l / g;
		for(ll i = 2; (i * i) <= nm; i++){
			ll cnt = 0, mlt = 1;
			while(nm % i == 0){
				nm /= i;
				cnt++;
				mlt *= i;
			}
			if(cnt) pr.pb(mlt);
		}
		if(nm > 1) pr.pb(nm);
		pair<ll, ll> bst = {1, 1e18};
		rep(i, (1 << (int)(pr.size()))){
			ll a = g, b = g;
			rep(j, pr.size()){
				if(i & (1 << j)) a *= pr[j];
				else b *= pr[j];
			}
			if((a + b) < (bst.fi + bst.se)) bst = {a, b};
		}
		cout << bst.fi << " " << bst.se << endl;
	}
	else cout << "-1 -1" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
