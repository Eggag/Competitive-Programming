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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n;
	cin >> n;
	vector<pi> p;
	rep(i, n){
		int k;
		cin >> k;
		vi a(k);
		int mx = 0;
		rep(j, k){
			cin >> a[j];
			mx = max(mx, a[j] - j);
		}
		p.pb(mp(mx, k));
	}
	sort(all(p));
	int l = 0, r = 1e9 + 10;
	while(l < r){
		int mid = (l + r) / 2;
		int cur = mid;
		int f = 1;
		rep(j, n){
			if(cur <= p[j].fi) f = 0;
			cur += p[j].se;
		}
		if(f) r = mid;
		else l = mid + 1;
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
