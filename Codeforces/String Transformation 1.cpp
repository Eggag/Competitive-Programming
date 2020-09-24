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

vi gr[30];

bool cmp(pair<pair<char, char>, int> a, pair<pair<char, char>, int> b){
	return a.fi.se - a.fi.fi < b.fi.se - b.fi.fi;
}

void solve(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	DSU dsu(30);
	rep(i, 30) gr[i].clear();
	rep(i, n){
		if(a[i] > b[i]){
			//no way we can make
			cout << -1 << endl;
			return;
		}
	}
	vector<pair<pair<char, char>, int>> v;
	rep(i, n) v.pb(mp(mp(a[i], b[i]), i));
	sort(all(v), cmp);
	int ans = 0;
	rep(i, n){
		int cur = v[i].fi.fi - 'a';
		int cur1 = v[i].fi.se - 'a';
		if(!dsu.sameset(cur, cur1)){
			ans++;
			dsu.merge(cur, cur1);
		}
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
