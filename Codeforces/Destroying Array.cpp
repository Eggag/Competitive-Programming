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
			tmp.parent = i; tmp.sum = -1;
			dsu.pb(tmp);
		}
	}
	void reset(int n){
		dsu.clear();
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = -1;
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
	int n;
	cin >> n;
	int a[n];
	rep(i, n) cin >> a[i];
	int o[n];
	rep(i, n) cin >> o[i], o[i]--;
	reverse(o, o + n);
	//the idea is to add elements from the end
	ll mx = 0LL;
	DSU dsu(n);
	vector<ll> ans;
	ans.pb(0);
	rep(i, n){
		dsu.dsu[o[i]].sum = a[o[i]];
		if(o[i] - 1 >= 0 && dsu.dsu[o[i] - 1].sum != -1) dsu.merge(o[i], o[i] - 1);
		if(o[i] + 1 < n && dsu.dsu[o[i] + 1].sum != -1) dsu.merge(o[i], o[i] + 1);
		mx = max(mx, dsu.getsum(o[i]));
		ans.pb(mx);
	}
	reverse(all(ans));
	repn(i, 1, n + 1) cout << ans[i] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
