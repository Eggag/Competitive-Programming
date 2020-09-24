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
	ll n, k;
	cin >> n >> k;
	vector<ll> p(n), c(n);
	rep(i, n) cin >> p[i], p[i]--;
	rep(i, n) cin >> c[i];
	ll ans = -1e18;
	rep(i, n){
		ll cur = i;
		ll tot = 0LL, mx = -1e18;
		vi vis(n, 0);
		ll nw = 0LL;
		rep(j, min(k, n)){
			if(vis[cur]) break;
			nw++;
			vis[cur] = 1;
			tot += c[p[cur]];
			mx = max(mx, tot);
			cur = p[cur];
		}
		if(tot <= 0){
			ans = max(ans, mx);
			continue;
		}
		ans = max(ans, mx);
		if(k <= nw) continue;
		ll nm = k / nw;
		ll rem = k % nw;
		ans = max(ans, (nm - 1) * tot + mx);
		ll tot1 = 0LL, mx1 = -1e18;
		cur = i;
		rep(j, rem + 1){
			mx1 = max(mx1, tot1);
			tot1 += c[p[cur]];
			cur = p[cur];
		}
		ans = max(ans, nm * tot + mx1);
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
