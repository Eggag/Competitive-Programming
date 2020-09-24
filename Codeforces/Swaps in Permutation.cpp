#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
vi a;

struct DSU{
	int S;
	struct node{
		int parent; vector<ll> sum;
	};
	vector<node> dsu;
	DSU(int n){
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = {i};
			dsu.pb(tmp);
		}
	}
	void reset(int n){
		dsu.clear();
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = {i};
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
		if(dsu[u].sum.size() < dsu[v].sum.size()) swap(u, v);
		dsu[v].parent = u;
		//dsu[u].sum += dsu[v].sum;
		rep(i, dsu[v].sum.size()){
			dsu[u].sum.pb(dsu[v].sum[i]);
		}
	}
	bool sameset(int u, int v){
		if(root(u) == root(v)) return true;
		return false;
	}	
	//ll getsum(int u){
	//	return dsu[root(u)].sum;
	//}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n){
		int x;
		cin >> x;
		a.pb(x);
	}
	DSU dsu(n);
	rep(i, m){
		int x, y;
		cin >> x >> y;
		x--, y--;
		dsu.merge(x, y);
	}
	vi ans(n);
	rep(i, n) if(dsu.root(i) == i){
		//we have the cc
		vector<ll> cur = dsu.dsu[i].sum; //make it simpler
		vi tmp;
		rep(j, cur.size()) tmp.pb(a[cur[j]]);
		sort(all(tmp));
		reverse(all(tmp));
		sort(all(cur));
		rep(j, cur.size()){
			ans[cur[j]] = tmp[j];
		}
	}
	rep(i, n) cout << ans[i] << " \n"[i == n - 1];
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
