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
#define y1 qwertyuiop

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n, x1, y1, x2, y2;

ll dist(ll a, ll b, ll c, ll d){
	return sq(a - c) + sq(b - d);
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	return dist(x1, y1, a.fi, a.se) < dist(x1, y1, b.fi, b.se);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> x1 >> y1 >> x2 >> y2;
	vector<pair<ll, ll>> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	sort(all(p), cmp);
	ll mn = 1e18;
	rep(i, n + 1){
		ll mx1 = 0LL, mx2 = 0LL;
		rep(j, i) mx1 = max(mx1, dist(x1, y1, p[j].fi, p[j].se));
		repn(j, i, n) mx2 = max(mx2, dist(x2, y2, p[j].fi, p[j].se));
		mn = min(mn, mx1 + mx2);
	}
	cout << mn << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
