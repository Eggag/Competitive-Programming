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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input1.txt", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> h(n), w(n);
	ll tot = 0LL, mx = 0LL, rem = 0LL;
	set<ll> st;
	int f = 1;
	rep(i, n){
		cin >> h[i], h[i]++, mx = max(mx, h[i]), st.insert(h[i]);
		if(i && h[i] < h[i - 1]) f = 0;
	}
	rep(i, n) cin >> w[i], w[i]++, tot += w[i] - 1, rem += w[i] - 1;
	if(f){
		ll ans = 0LL;
		rep(i, n){
			ll mn = h[i];
			rem -= w[i] - 1;
			ll one = ((mn * (mn - 1)) / 2) % MOD;
			ll two = ((w[i] * (w[i] - 1)) / 2) % MOD;
			ll add = (one * two) % MOD;
			(ans += add) %= MOD;
			ll two1 = (rem % MOD * (w[i] - 1)) % MOD;
			add = (one * two1) % MOD;
			if(i != (n - 1)) (ans += add) %= MOD;
		}
		cout << ans << endl;
		return 0;
	}
	if(st.size() == 1){
		tot++;
		tot %= MOD;
		ll one = ((h[0] * (h[0] - 1)) / 2) % MOD;
		ll two = (((tot - 1) * tot) / 2) % MOD;
		cout << (one * two) % MOD << endl;
		return 0;
	}
	if(n <= 1000){
		ll ans = 0LL;
		rep(i, n){
			ll mn = 1e18;
			repn(j, i, n){
				mn = min(mn, h[j]);
				ll one = ((mn * (mn - 1)) / 2) % MOD;
				ll two = ((w[i] - 1) * (w[j] - 1)) % MOD;
				if(j == i) two = ((w[i] * (w[i] - 1)) / 2) % MOD;
				ll add = (one * two) % MOD;
				(ans += add) %= MOD;
			}
		}
		cout << ans << endl;
		return 0;
	}
	if(mx <= 3){
		tot++;
		tot %= MOD;
		ll ans = ((tot * (tot - 1)) / 2) % MOD;
		ll cur = 0LL;
		rep(i, n){
			if(h[i] == 3){
				cur += w[i] - 1;
			}
			else{
				cur++;
				cur %= MOD;
				(ans += ((2 * cur * (cur - 1)) / 2) % MOD) %= MOD;
				cur = 0;
			}
		}
		cur++;
		cur %= MOD;
		(ans += ((2 * cur * (cur - 1)) / 2) % MOD) %= MOD;
		cout << ans << endl;
		return 0;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
