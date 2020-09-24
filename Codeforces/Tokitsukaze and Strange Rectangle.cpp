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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool cmp(pi a, pi b){
	return a.se < b.se;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	sort(all(p), cmp);
	map<int, int> cnt;
	map<int, vi> nm;
	set<int> st;
	ordered_set<int> ost;
	rep(i, n){
		cnt[p[i].fi]++;
		if(cnt[p[i].fi] == 1){
			ost.insert(p[i].fi);
		}
		nm[p[i].se].pb(p[i].fi);
		st.insert(p[i].se);
	}
	for(pair<int, vi> x : nm) sort(all(nm[x.fi]));
	ll ans = 0LL;
	for(int i : st){
		rep(j, nm[i].size()){
			ll bef = 0LL, aft = 0LL;
			bef = ost.order_of_key(nm[i][j]) + 1 - (!j ? 0 : ost.order_of_key(nm[i][j - 1]) + 1);
			if(j) assert(nm[i][j] > nm[i][j - 1]);
			aft = (ll)(ost.size() - ost.order_of_key(nm[i][j]));
			ans += bef * aft;
		}
		rep(j, nm[i].size()){
			cnt[nm[i][j]]--;
			if(!cnt[nm[i][j]]) ost.erase(ost.find(nm[i][j]));
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
