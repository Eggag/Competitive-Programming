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
#define ar array
const int mxN = 1e5 + 5;
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
template<class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
int n, q;
 
bool cmp(pair<pi, int> a, pair<pi, int> b){
	return (a.fi.fi + a.fi.se) < (b.fi.fi + b.fi.se);
}
 
bool cmp1(pair<pi, int> a, pair<pi, int> b){
	return a.fi.fi > b.fi.fi;
}
 
bool cmp2(ar<int, 4> a, ar<int, 4> b){
	return a[0] > b[0];
}
 
//segment tree
 
ordered_set<pi> t[4 * mxN];
int a[mxN];
 
int query(int v, int tl, int tr, int l, int r, int x){
	if(l > r) return 0;
	if(l == tl && r == tr){
		return (t[v].size() - t[v].order_of_key({x, -1}));
	}
	int tm = (tl + tr) / 2;
	return query(v * 2, tl, tm, l, min(r, tm), x) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}
 
void update(int v, int tl, int tr, int pos, int new_val){
	t[v].insert({new_val, pos});
	if(tl != tr){
		int tm = (tl + tr) / 2;
		if(pos <= tm) update(v * 2, tl, tm, pos, new_val);
		else update(v * 2 + 1, tm + 1, tr, pos, new_val);
	}
	else a[pos] = new_val;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> q;
	vector<pair<pi, int>> p(n);
	rep(i, n) cin >> p[i].fi.fi >> p[i].fi.se;
	sort(all(p), cmp);
	rep(i, n) p[i].se = i;
	vector<pair<pi, int>> p1 = p;
	sort(all(p), cmp1);
	vector<ar<int, 4>> ask(q);
	rep(i, q) cin >> ask[i][0] >> ask[i][1] >> ask[i][2];
	//sort the queries by a
	rep(i, q) ask[i][3] = i;
	sort(all(ask), cmp2);
	rep(i, n) a[p1[i].se] = p1[i].fi.se;
	vi ans(q, 0);
	int cur = 0;
	rep(i, q){
		//do all the updates
		while(cur < n && p[cur].fi.fi >= ask[i][0]){
			update(1, 0, n - 1, p[cur].se, p[cur].fi.se);
			cur++;
		}
		//find the lo (the first one not less than c)
		int l = 0, r = n - 1;
		while(l < r){
			int mid = (l + r) / 2;
			if((p1[mid].fi.fi + p1[mid].fi.se) >= ask[i][2]) r = mid;
			else l = mid + 1;
		}
		if(p1[l].fi.fi + p1[l].fi.se >= ask[i][2]){
			ans[ask[i][3]] = query(1, 0, n - 1, l, n - 1, ask[i][1]);
		}
	}
	rep(i, q) cout << ans[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
