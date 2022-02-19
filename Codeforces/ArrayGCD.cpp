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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	vector<pair<ll, ll>> p(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> p[i].fi >> p[i].se;
	sort(all(p));
	reverse(all(p));
	ll ans = 0;
	rep(j, n){
		vector<ll> owo(m, 0);
		rep(i, m){
			ll uwu = a[j];
			ll cnt = 0;
			while(uwu % p[i].fi == 0){
				uwu /= p[i].fi;
				cnt++;
			}
			owo[i] = cnt;
		}
		__int128 mx = 0, mx1 = 0;
		rep(i, m){
			__int128 x = p[i].fi, y = p[i].se - owo[i];
			mx = max(mx, x * y);
			mx1 = max(mx1, x * min(x - 1, y));
		}
		__int128 l = mx1, r = mx;
		while(l < r){
			__int128 mid = (l + r) / 2;
			int pos = 1;
			rep(i, m){
				__int128 cr = p[i].fi, mlt = p[i].fi;
				__int128 c = (__int128)(p[i].se - owo[i]);
				while(cr <= mid){
					c -= mid / cr;
					if(c <= 0) break;
					cr *= mlt;
				}
				if(c > 0){
					pos = 0;
					break;
				}
			}
			if(pos) r = mid;
			else l = mid + 1;
		}
		(ans += (l % MOD)) %= MOD;
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
