#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

template<class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

bool cmp(array<int, 3> a, array<int, 3> b){
	return a[0] < b[0];
}

bool cmp1(pi a, pi b){
	if(a.fi != b.fi) return a.fi < b.fi;
	return a.se > b.se;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	vector<pi> p(n);
	rep(i, n) cin >> a[i], p[i] = {a[i], i};
	sort(all(p), cmp1);
	int m;
	cin >> m;
	ordered_set<pi> st;
	vector<array<int, 3>> q(m);
	vi ans(m);
	rep(i, m) cin >> q[i][0] >> q[i][1], q[i][2] = i;
	sort(all(q), cmp);
	int ind = n - 1;
	int prev = 0;
	rep(i, m){
		int df = q[i][0] - prev;
		while(df--) st.insert({p[ind].se, p[ind].fi}), ind--;
		prev = q[i][0];
		pi res = *st.find_by_order(q[i][1] - 1);
		ans[q[i][2]] = res.se;
	}
	rep(i, m) cout << ans[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
