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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

vi gr[mxN];
int cnt[mxN];

bool cmp(int a, int b){
	return cnt[a] < cnt[b];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m, t;
	cin >> n >> m >> t;
	vector<ll> a(n);
	rep(i, n) cin >> a[i], cnt[a[i]]++;
	vector<ll> q(t);
	rep(i, t) cin >> q[i], q[i] -= n + 1;
	vector<ll> b;
	rep(i, m) b.pb(i + 1);
	sort(all(b), cmp);
	vector<ll> nxt = {0LL};
	rep(i, m - 1){
		ll cur = (ll)((i + 1) * (ll)(cnt[b[i + 1]] - cnt[b[i]]));
		if(cur) nxt.pb(nxt[nxt.size() - 1] + cur);
	}
	rep(i, t){
		int l = 0, r = nxt.size() - 1;
		while(l < r){
			int mid = (l + r + 1) / 2;
			if(q[i] >= nxt[mid]) l = mid;
			else r = mid - 1;
		}
		gr[l].pb(i);
	}
	int ind = 0;
	vector<ll> ans(t, -1);
	rep(i, m){
		ost.insert(b[i]);
		ll cur = 0;
		if(i < (m - 1)) cur = (ll)((i + 1) * (ll)(cnt[b[i + 1]] - cnt[b[i]]));
		if(cur || (i == (m - 1))){
			rep(j, gr[ind].size()){
				ll num = (q[gr[ind][j]] - nxt[ind]) % (i + 1);
				ll nm = *ost.find_by_order(num);
				ans[gr[ind][j]] = nm;
			}
			ind++;
		}
	}
	rep(i, t) cout << ans[i] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
