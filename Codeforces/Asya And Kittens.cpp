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
		int parent; vi kittens;
	};
	vector<node> dsu;
	DSU(int n){
		S = n;
		rep(i, n){
			node tmp;
                        //set parent to itself
			tmp.parent = i; tmp.kittens = {i};
			dsu.pb(tmp);
		}
	}
	void reset(int n){
		dsu.clear();
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.kittens = {i};
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
		//this line makes the difference betweem AC and MLE
		//we use less memory by choosing to grow a few larger cells over many little cells
		if(dsu[v].kittens.size() > dsu[u].kittens.size()) swap(u, v);
		dsu[v].parent = u;
		rep(i, dsu[v].kittens.size()) dsu[u].kittens.pb(dsu[v].kittens[i]);
	}
	bool sameset(int u, int v){
		if(root(u) == root(v)) return true;
		return false;
	}
	vi getall(int u){
		return dsu[root(u)].kittens;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	DSU dsu(n);
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		dsu.merge(a, b);
	}
	for(int x : dsu.getall(dsu.root(1))) cout << x + 1 << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/