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

unordered_map<ll, int> m[26];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, K;
	ll s;
	cin >> n >> K >> s;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> b, c;
	rep(i, n / 2) b.pb(a[i]);
	repn(i, n / 2, n) c.pb(a[i]);
	vector<ll> fact(19, 0);
	fact[1] = 1LL;
	repn(i, 2, 19) fact[i] = 1LL * i * fact[i - 1];
	ll ans = 0;
	rep(i, (1 << ((int)c.size()))){
		vector<ll> cr;
		rep(j, c.size()) if(i & (1 << j)) cr.pb(c[j]);
		rep(j, (1 << ((int)cr.size()))) if(__builtin_popcount(j) <= K){
			ll tot = 0LL;
			rep(k, cr.size()){
				if(j & (1 << k)){
					if(cr[k] <= 18) tot += fact[cr[k]];
					else{
						tot = 1e18;
						break;
					}
				}
				else tot += cr[k];
				if(tot > s) break;
			}
			int nm = __builtin_popcount(j);
			if(tot <= s){
				rep(k, K - nm + 1) m[k][tot]++;
			}
		}
	}
	rep(i, (1 << (n / 2))){
		vector<ll> cr;
		rep(j, n / 2) if(i & (1 << j)) cr.pb(b[j]);
		rep(j, (1 << ((int)cr.size()))) if(__builtin_popcount(j) <= K){
			ll tot = 0LL;
			rep(k, cr.size()){
				if(j & (1 << k)){
					if(cr[k] <= 18) tot += fact[cr[k]];
					else{
						tot = 1e18;
						break;
					}
				}
				else tot += cr[k];
				if(tot > s) break;
			}
			if(tot == s) ans++;
			int nm = __builtin_popcount(j);
			if(tot < s) ans += m[nm][s - tot];
		}
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
