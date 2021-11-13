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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n, a, r, m;
ll le[mxN], ri[mxN];
ll h[mxN];

ll check(ll g){
	ll cst = 0LL;
	int st = lb(h, h + n, g) - h;
	if(st == n) return ((g * n) - (le[n - 1])) * a;
	ll lo = (g * st) - (st ? le[st - 1] : 0LL);
	ll ro = ri[st] - (g * (n - st));
	cst += m * min(lo, ro);
	if(le[n - 1] < (g * n)) return cst + ((g * n) - le[n - 1]) * a;
	else return cst + (le[n - 1] - (g * n)) * r;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> a >> r >> m;
	ll a1 = a, r1 = r, m1 = m;
	ll sum = 0LL;
	rep(i, n) cin >> h[i], sum += h[i];
	m = min(m, a1 + r1);
	sort(h, h + n);
	if(n == 1 || !a || !r){
		cout << "0\n";
		return 0;
	}
	le[0] = h[0];
	repn(i, 1, n) le[i] = le[i - 1] + h[i];
	ri[n - 1] = h[n - 1];
	for(int i = n - 2; i >= 0; i--) ri[i] = ri[i + 1] + h[i];
	ll ans = 1e18;
	rep(i, n) ans = min(ans, check(h[i]));
	for(ll i = max(h[0], (sum / n) - (ll)(2e6)); i <= min(h[n - 1], (sum / n) + (ll)(2e6)); i++) ans = min(ans, check(i));
	rep(i, n){
		for(int j = max(h[0], h[i] - 50); j <= min(h[n - 1], h[i] + 50); j++) ans = min(ans, check(j));
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
