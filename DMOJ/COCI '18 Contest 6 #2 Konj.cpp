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
const int mxN = 305;

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

vi pp[mxN][mxN];
int D[mxN][mxN];
char s[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	DSU dsu(200005);
	int cnt = 1;
	rep(i, n){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		swap(a, b);
		swap(c, d);
		if(a == c){
			repn(j, min(b, d), max(b, d) + 1) D[a][j] = cnt;
			rep(j, pp[a][b].size()) dsu.merge(cnt, pp[a][b][j]);
			rep(j, pp[c][d].size()) dsu.merge(cnt, pp[c][d][j]);
			pp[a][b].pb(cnt);
			pp[c][d].pb(cnt);
		}
		else{
			repn(j, min(a, c), max(a, c) + 1) D[j][b] = cnt;
			rep(j, pp[a][b].size()) dsu.merge(cnt, pp[a][b][j]);
			rep(j, pp[c][d].size()) dsu.merge(cnt, pp[c][d][j]);
			pp[a][b].pb(cnt);
			pp[c][d].pb(cnt);
		}
		cnt++;
	}
	int x, y;
	cin >> y >> x;
	int mx = 0, mx1 = 0;
	int mn = 1e9, mn1 = 1e9;
	repn(i, 0, mxN){
		repn(j, 0, mxN){
			if(dsu.sameset(D[i][j], D[x][y])){
				s[i][j] = '#', mx = max(mx, i), mx1 = max(mx1, j);
				mn = min(mn, i), mn1 = min(mn1, j);
			}
			else s[i][j] = '.';
		}
	}
	for(int i = mx; i >= mn; i--){
		repn(j, mn1, mx1 + 1) cout << s[i][j];
		cout << endl;
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
