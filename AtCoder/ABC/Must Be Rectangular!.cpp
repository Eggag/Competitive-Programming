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
const int MAXN = 1e5;

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

ll a[2 * MAXN], b[2 * MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	DSU dsu(2 * MAXN);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	rep(i, n){
		int x, y;
		cin >> x >> y;
		x-- , y--;
		dsu.merge(x, MAXN + y);
	}
	rep(i, MAXN){
		a[dsu.root(i)]++;
		b[dsu.root(i + MAXN)]++;
	}
	ll ans = 0;
	rep(i, 2 * MAXN) if(dsu.root(i) == i) ans += a[i] * b[i];
	cout << ans - n << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
