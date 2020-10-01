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
const int logn = 22;
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct DSU{
	int S;
	struct node{
		int parent; ll sum;
	};
	vector<node> dsu;
	DSU(int n){
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	int root(int u){
		if(dsu[u].parent == u) return u;
		dsu[u].parent = root(dsu[u].parent);
		return dsu[u].parent;
	}
	void merge(int u, int v){
		u = root(u); v = root(v);
		if(u == v) return;
		if(getsum(u) < getsum(v)) swap(u, v);
		dsu[v].parent = u;
		dsu[u].sum += dsu[v].sum;
	}
	bool sameset(int u, int v){
		if(root(u) == root(v)) return true;
		return false;
	}	
	ll getsum(int u){
		return dsu[root(u)].sum;
	}
};

int n;
int a[mxN], mn[logn][mxN];
 
int minQ(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return min(mn[t][l], mn[t][r - (1 << t)]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	vector<pair<pi, int>> p(n);
	rep(i, n) cin >> p[i].fi.fi >> p[i].fi.se, p[i].se = i;
	sort(all(p));
	rep(i, n) a[i] = p[i].fi.se;
	memcpy(mn[0], a, sizeof a);
	for(int l = 0; l < logn - 1; l++){
		for(int i = 0; i + (2 << l) <= n; i++){
			mn[l + 1][i] = min(mn[l][i], mn[l][i + (1 << l)]);
		}
	}
	DSU dsu(n);
	set<int> st;
	rep(i, n) st.insert(i + 1);
	int nxt = *(--st.end());
	int ind = 0;
	int le = 0;
	vi nw;
	while(ind < n){
		auto it = st.find(p[ind].fi.se);
		if(it != st.end()) st.erase(it);
		if(p[ind].fi.se == nxt){
			repn(i, le + 1, ind + 1) dsu.merge(i, i - 1);
			int l = 0, r = ind;
			while(l < r){
				int mid = (l + r) / 2;
				if(minQ(0, mid + 1) <= p[ind].fi.se) r = mid;
				else l = mid + 1;
			}
			if(minQ(0, l + 1) > p[ind].fi.se) l++;
			if(nw.size()){
				auto it = lb(all(nw), l);
				if(it != nw.end()) dsu.merge(*it, ind);
			}
			nw.pb(ind);
			le = ind + 1;
			auto it = st.find(p[ind].fi.se);
			if(it != st.end()) st.erase(it);
			if(st.size()) nxt = *(--st.end());
		}
		ind++;
	}
	vi ans(n, 0);
	rep(i, n) ans[p[i].se] = dsu.getsum(i);
	rep(i, n) cout << ans[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
