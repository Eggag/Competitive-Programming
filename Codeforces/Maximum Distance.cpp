#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll s[100005];

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
        		//set parent to itself
			tmp.parent = i; tmp.sum = s[i];
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
                //it works if a there is a subset of subset of a set (dfs)
		dsu[u].parent = root(dsu[u].parent);
		return dsu[u].parent;
	}
	void merge(int u, int v){
		u = root(u); v = root(v);
		if(u == v) return;
		//we choose to grow bigger sets over little sets (merge / unite by rank)
		//that alows us to use less memory and avoid MLE
		if(getsum(u) < getsum(v)) swap(u, v);
		//we don't erase the sum
		//it is fine since it is not pointing to itself
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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	rep(i, 100005) s[i] = 0LL;
	vi x;
	rep(i, k){
		int a;
		cin >> a;
		a--;
		s[a] = 1LL;
		x.pb(a);
	}
	DSU dsu(n);
	vector<pair<int, pi>> edges;
	rep(i, m){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edges.pb({c, {a, b}});
	}
	sort(all(edges));
	int ans = 0;
	for(pair<int, pi> u : edges){
		dsu.merge(u.se.fi, u.se.se);
		if(dsu.getsum(x[0]) == k){
			ans = u.fi;
			break;
		}
	}
	rep(i, k) cout << ans << " \n"[i == k - 1];
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
