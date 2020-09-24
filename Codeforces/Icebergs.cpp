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

ld solve(){
	int n;
	cin >> n;
	vector<pair<ld, ld>> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	ld res = 0.0;
	rep(i, n - 1) res += ((p[i].fi * p[i + 1].se)) - ((p[i + 1].fi * p[i].se));
	res += p[n - 1].fi * p[0].se;
	res -= p[n - 1].se * p[0].fi;
	res = abs(res);
	return (ld)(res / 2.0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	ld tot = 0.0;
	rep(i, n) tot += solve();
	ll ret = (ll)(tot);
	cout << ret << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
