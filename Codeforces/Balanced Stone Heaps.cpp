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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ll h[mxN], h1[mxN];

bool check(int g){
	if(!g) return 1;
	for(int i = n - 1; i >= 2; i--){
		ll mx = h[i] - g;
		if(mx < 0) return 0;
		mx = min(mx, h1[i]);
		h[i - 2] += 2 * (mx / 3);
		h[i - 1] += (mx / 3);
		h[i] -= (mx / 3) * 3;
	}
	rep(i, n) if(h[i] < g) return 0;
	return 1;
}

void solve(){
	cin >> n;
	rep(i, n) cin >> h[i], h1[i] = h[i];
	int l = 0, r = 1e9 + 5;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
		rep(i, n) h[i] = h1[i];
	}
	cout << l << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
