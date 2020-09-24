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
#define inf 0x3f3f3f3f
const int mxN = 1e5 + 5;
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
int n, le;
int ind[mxN], mn[mxN], vis[mxN];
int st[mxN], fin[mxN], dep[mxN];
int num = 0, rt = -1;
vi g[mxN];
vector<vi> up;
 
void dfs0(int cur, int prev, int d = 0){
	mn[cur] = cur;
	dep[cur] = d;
	for(int x : g[cur]) if(x != prev){
		dfs0(x, cur, d + 1);
		mn[cur] = min(mn[cur], mn[x]);
	}
}
 
bool cmp(int a, int b){
	return mn[a] < mn[b];
}
 
vi ord;
 
void dfs(int cur, int prev = rt){
	st[cur] = num++;
	up[cur][0] = prev;
	repn(i, 1, le + 1) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for(int x : g[cur]) if(x != prev) dfs(x, cur);
	ord.pb(cur);
	fin[cur] = num++;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	memset(mn, inf, sizeof(mn));
	rep(i, n){
		int a;
		cin >> a;
		a--;
		if(a >= 0){
			g[i].pb(a);
			g[a].pb(i);
		}
		else rt = i;
	}
	dfs0(rt, -1); //get the minimums
	rep(i, n) sort(all(g[i]), cmp);
	up.resize(n);
	le = 1;
	while((1 << le) <= n) le++;
	rep(i, n) up[i].resize(le + 1);
	dfs(rt);
	rep(i, n) ind[ord[i]] = i;
	set<pi> st;
	rep(i, n) st.insert({ind[i], i}); //we sort by the index from the toposort
	rep(i, q){
		int t;
		cin >> t;
		if(t == 1){
			int k;
			cin >> k;
			int lst = -1;
			rep(j, k){
				pi cur = *st.begin();
				st.erase(st.begin());
				vis[cur.se] = 1;
				lst = cur.se;
			}
			cout << lst + 1 << '\n';
		}
		else{
			//we use binary search + binary lifting
			//to find the first unvisited node above the deleted one
			int x;
			cin >> x;
			x--;
			if(x == rt || !vis[up[x][0]]){
				cout << 0 << '\n';
				vis[x] = 0;
				st.insert({ind[x], x});
				continue;
			}
			int nd = x;
			for(int j = le; j >= 0; j--){
				int nd1 = up[nd][j];
				if(vis[nd1]) nd = nd1;
			}
			vis[nd] = 0;
			st.insert({ind[nd], nd});
			cout << dep[x] - dep[nd] << '\n';
		}
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
