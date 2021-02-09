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
const int mxN = 1e5 + 5;
const int logn = 23;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[mxN], b[mxN], mn[logn][mxN];

int minQ(int l, int r) { // [l; r)
	int ret = 1e9;
	if(l == -1) ret = 0, l++;
	if(l == r) return 0;
	int t = __lg(r - l);
	ret = min({ret, mn[t][l], mn[t][r - (1 << t)]});
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n) cin >> a[i];
	vector<pi> sm;
	vi p(n, -1);
	int ans = -1e9;
	rep(i, n){
		while(sm.size() && sm.back().fi <= a[i]) sm.pop_back();
		if(sm.size()) p[i] = sm.back().se;
		sm.pb({a[i], i});
	}
	rep(i, n) b[i] = a[i] + (i ? b[i - 1] : 0);
	memcpy(mn[0], b, sizeof b);
	for(int l = 0; l < logn - 1; l++){
		for(int i = 0; i + (2 << l) <= n; i++){
			mn[l + 1][i] = min(mn[l][i], mn[l][i + (1 << l)]);
		}
	}
	rep(i, n){
		int prev = p[i];
		int cr = i;
		while(true){
			ans = max(ans, b[i] - minQ(prev, i) - a[cr]);
			if(prev == -1) break;
			cr = prev;
			prev = p[prev];
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
