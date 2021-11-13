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
	int n, m, x;
	cin >> n >> m >> x;
	vector<ll> h(n);
	rep(i, n) cin >> h[i];
	set<pair<ll, int>> st;
	rep(i, m) st.insert(mp(0LL, i));
	vector<ll> ans(m, 0LL);
	vi res(n);
	rep(i, n){
		pair<ll, int> mn = *st.begin();
		res[i] = mn.se;
		ans[mn.se] += h[i];
		st.erase(st.begin());
		st.insert(mp(mn.fi + h[i], mn.se));
	}
	ll mx = 0LL, mn = 1e18;
	rep(i, m) mx = max(mx, ans[i]), mn = min(mn, ans[i]);
	if((mx - mn) > x){
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	rep(i, n) cout << res[i] + 1 << " ";
	cout << '\n';
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
