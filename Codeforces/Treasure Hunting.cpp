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
const int mxN = 2e5 + 5;
const ll inf = 1e18;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

pair<int, ll> dp[2][4]; //{position, cost}
ll mn[mxN], mx[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<pair<ll, ll>> p(k);
	rep(i, mxN) mn[i] = inf, mx[i] = -inf;
	ll h = 0;
	rep(i, k){
		cin >> p[i].fi >> p[i].se;
		mn[p[i].fi] = min(mn[p[i].fi], p[i].se);
		mx[p[i].fi] = max(mx[p[i].fi], p[i].se);
		h = max(h, p[i].fi);
	}
	vi b(q);
	rep(i, q) cin >> b[i];
	sort(all(b));
	rep(i, 2) rep(j, 4) dp[i][j] = mp(0, inf);
	ll ans = 1e18;
	if(mn[1] == inf){
		int pos = 1;
		auto it = lb(all(b), pos);
		if(it != b.end()) dp[0][1] = mp(*it, (*it - pos));
		if(it != b.begin()){
			it--;
			dp[0][0] = mp(*it, (pos - *it));
		}
		ans = 0;
	}
	else{
		int pos = mx[1];
		auto it = lb(all(b), pos);
		if(it != b.end()) dp[0][3] = mp(*it, (*it - pos) + (pos - 1));
		if(it != b.begin()){
			it--;
			dp[0][2] = mp(*it, (pos - *it) + (pos - 1));
		}
		ans = pos - 1;
	}
	int cnt = 1;
	repn(i, 2, mxN) if(mn[i] != inf){
		int cr = cnt & 1, pr = 1 - cr;
		ll A = 1e18, B = 1e18;
		rep(j, 4) if(dp[pr][j].se != inf){
			A = min(A, dp[pr][j].se + abs(mx[i] - dp[pr][j].fi) + (mx[i] - mn[i]));
		}
		rep(j, 4) if(dp[pr][j].se != inf){
			B = min(B, dp[pr][j].se + abs(mn[i] - dp[pr][j].fi) + (mx[i] - mn[i]));
		}
		int pos = mn[i];
		auto it = lb(all(b), pos);
		if(it != b.end()) dp[cr][1] = mp(*it, A + (*it - pos));
		if(it != b.begin()){
			it--;
			dp[cr][0] = mp(*it, A + (pos - *it));
		}
		pos = mx[i];
		it = lb(all(b), pos);
		if(it != b.end()) dp[cr][3] = mp(*it, B + (*it - pos));
		if(it != b.begin()){
			it--;
			dp[cr][2] = mp(*it, B + (pos - *it));
		}
		ans = min(A, B);
		rep(j, 4) dp[pr][j] = mp(0, inf);
		cnt++;
	}
	cout << ans + h - 1 << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
