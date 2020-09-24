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
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	partial_sum(all(a), a.begin());
	vector<ll> pos(n);
	rep(i, n - k + 1) pos[i] = a[i + k - 1] - (!i ? 0 : (a[i - 1]));
	vector<pair<ll, int>> best(n);
	best[n - k] = {pos[n - k], n - k};
	for(int i = n - k - 1; i >= 0; i--){
		best[i].fi = best[i + 1].fi;
		best[i].se = best[i + 1].se;
		if((pos[i]) >= best[i + 1].fi){
			best[i].fi = pos[i];
			best[i].se = i;
		}
	}
	ll ans = 0;
	pi res = {-1, -1};
	rep(i, n - (2 * k) + 1){
		if((pos[i] + best[i + k].fi) > ans){
			ans = pos[i] + best[i + k].fi;
			res = {i, best[i + k].se};
		}
	}
	cout << res.fi + 1 << " " << res.se + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
