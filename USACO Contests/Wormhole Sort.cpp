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

int pos[100005];
int a[100005], b[100005], w[100005];
int n, m;

bool check(int num){
	//num is the minimal width we allow
	//so we only keep the edges with those values, and try to sort
	//the cows with those edges
	DSU dsu(n);	
	rep(i, m) if(w[i] >= num) dsu.merge(a[i], b[i]); //they are connected
	rep(i, n) if(!dsu.sameset(i, pos[i])) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
	cin >> n >> m;
	vi c(n);
	rep(i, n){
		int p;
		cin >> p;
		p--;
		c[i] = p;
		pos[p] = i;
	}
	rep(i, m) cin >> a[i] >> b[i] >> w[i], a[i]--, b[i]--;
	if(is_sorted(all(c))){
		cout << -1 << endl;
		return 0;
	}
	int l = 1, r = 1e9 + 10;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
