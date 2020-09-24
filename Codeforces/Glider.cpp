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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	ll h;
	cin >> n >> h;
	vector<pair<ll, ll>> x(n);
	vi p;
	rep(i, n) cin >> x[i].fi >> x[i].se, p.pb(x[i].se - x[i].fi);
	partial_sum(all(p), p.begin());
	vector<ll> segs;
	rep(i, n - 1) segs.pb(x[i + 1].fi - x[i].se);
	segs.pb(1e18);
	vector<ll> segs1 = segs;
	partial_sum(all(segs1), segs1.begin());
	ll ans = 0;
	rep(i, n){
		ll l = i, r = segs1.size() - 1;
		ll num = (!i ? 0 : segs1[i - 1]);
		while(l < r){
			ll mid = (l + r + 1) / 2;
			if((segs1[mid] - num) < h) l = mid;
			else r = mid - 1;
		}
		if(l < (segs1.size() - 1) && (segs1[l] - num) < h) l++;
		ll cur = p[l] - (!i? 0 : p[i - 1]);
		cur += segs1[l] - num;
		cur += h - (segs1[l] - num);
		ans = max(ans, cur);
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
