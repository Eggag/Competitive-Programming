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
			tmp.parent = i; tmp.sum = 1;
			dsu.pb(tmp);
		}
	}
	void reset(int n){
		dsu.clear();
		S = n;
		rep(i, n){
			node tmp;
			tmp.parent = i; tmp.sum = 0;
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
                //we don't erase the sum
                //it is fine since it is not pointing to itself
		if(rand() & 1) swap(u, v);
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

const int MOD = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	DSU dsu0(n), dsu1(n);
	rep(i, n - 1){
		int a, b, c;
		cin >> a >> b >> c;
		(c ? dsu1 : dsu0).merge(a - 1, b - 1);
	}
	ll ret = 0LL;
	rep(i, n) if(dsu0.root(i) == i && (dsu0.getsum(i))) ret += (dsu0.getsum(i)) * (dsu0.getsum(i) - 1) * 1LL;
	rep(i, n) if(dsu1.root(i) == i && (dsu1.getsum(i))) ret += (dsu1.getsum(i)) * (dsu1.getsum(i) - 1) * 1LL;
	rep(i, n) if(dsu0.getsum(i) > 1 && dsu1.getsum(i) > 1){
		ret += 1LL * (dsu0.getsum(i) - 1) * (dsu1.getsum(i) - 1);
	}
	cout << ret << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
