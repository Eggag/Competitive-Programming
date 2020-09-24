#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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
	void reset(int n){
		dsu.clear();
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	freopen("walk.in", "r", stdin);
//	freopen("walk.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, pair<ll, ll>>> dists;
	for(ll i = 1LL; i <= n; i++) for(ll j = i + 1; j <= n; j++){
		dists.pb(mp((ll)((ll)(2019201913 * i + 2019201949 * j) % 2019201997), mp(i, j)));
	}
	sort(all(dists));
	DSU dsu(n + 1);
	int cur = 0;
	rep(i, (n - k)){
		while(true){
			if(!dsu.sameset(dists[cur].se.fi, dists[cur].se.se)){
				dsu.merge(dists[cur].se.fi, dists[cur].se.se);
				cur++;
				break;
			}
			else cur++;
		}	
	}
	repn(i, cur, dists.size()){
		if(!dsu.sameset(dists[i].se.fi, dists[i].se.se)){
			cout << dists[i].fi << endl;
			break;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
