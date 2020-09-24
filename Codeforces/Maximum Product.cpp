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
	vector<ll> pos, neg;
	rep(i, n){
		ll x;
		cin >> x;
		if(x >= 0) pos.pb(x);
		else neg.pb(x);
	}
	sort(all(pos));
	reverse(all(pos));
	sort(all(neg));
	reverse(all(neg));
	ll ans = -1e18;
	rep(j, 6) rep(k, 2) rep(l, 2){
		if((int)pos.size() >= (5 - j) && (int)neg.size() >= j){
			ll cur = 1LL;
			if(k) rep(i, j) cur *= neg[i];
			else{
				for(int i = (int)neg.size() - 1; i > (int)(neg.size() - 1 - j); i--){
					cur *= neg[i];
				}
			}
			if(l) rep(i, 5 - j) cur *= pos[i];
			else{
				for(int i = (int)pos.size() - 1; i > (int)(pos.size() - 1 - (5 - j)); i--){
					cur *= pos[i];
				}
			}
			ans = max(ans, cur);
		}
	}
	cout << ans << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
