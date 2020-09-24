#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi p(n), c(n);
	vector<pair<pi, int>> a(n);
	rep(i, n) cin >> p[i];
	rep(i, n) cin >> c[i];
	rep(i, n){
		a[i] = mp(mp(p[i], c[i]), i);
	}
	vector<ll> ans(n);
	sort(all(a));
	vi v1, v2;
	rep(i, n){
		ans[a[i].se] = a[i].fi.se;
		for(auto x : v1) ans[a[i].se] += x;
		v2.pb(a[i].fi.se);
		sort(v2.rbegin(), v2.rend());
		v1.clear();
		rep(j, min(k, (int)v2.size())) v1.pb(v2[j]);
		v2 = v1;
	}
	rep(i, n){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
