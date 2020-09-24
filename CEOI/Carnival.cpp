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

int query(vi a){
	if(a.size() == 1) return 1;
	cout << (int)(a.size()) << " ";
	rep(i, a.size()) cout << a[i] + 1 << " ";
	cout << endl;
	int ans;
	cin >> ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	DSU dsu(n);
	rep(i, n) if(dsu.getsum(i) == 1){
		vi f, s;
		/*
		rep(j, n / 2) if(j != i) f.pb(j);
		repn(j, n / 2, n) if(j != i) s.pb(j);
		*/
		int j;
		for(j = 0; j < n; j++) if(j != i){
			if(f.size() == ((n - 1) / 2)) break;
			f.pb(j);
		}
		for(; j < n; j++) if(j != i) s.pb(j);
		/*
		cout << "----" << endl;
		rep(j, f.size()) cout << f[j] << " ";
		cout << endl;
		rep(j, s.size()) cout << s[j] << " ";
		cout << endl;
		cout << "----" << endl;
		*/
		vi b;
		vi f1 = f, s1 = s;
		f1.pb(i);
		s1.pb(i);
		if(f.size() && query(f) == query(f1)) b = f;	
		else if(s.size() && query(s) == query(s1)) b = s;
		while((int)b.size() > 0 && (int)(b.size()) != 1){
			int m = b.size();
			vi f2, s2;
			rep(j, m / 2) f2.pb(b[j]);
			repn(j, m / 2, m) s2.pb(b[j]);
			vi f3 = f2, s3 = s2;
			f3.pb(i);
			s3.pb(i);
			if(f2.size() && query(f2) == query(f3)) b = f2;	
			else if(s2.size() && query(s2) == query(s3)) b = s2;
		}
		if((int)b.size() == 1) dsu.merge(i, b[0]);
	}
	int col = 1;
	vi ans(n);
	rep(i, n) if(dsu.root(i) == i){
		rep(j, n) if(dsu.root(j) == i) ans[j] = col;
		col++;
	}
	cout << 0 << " ";
	rep(i, n) cout << ans[i] << " ";
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
