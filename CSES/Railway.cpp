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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m, k;
vi g[mxN];
vi ans;
vector<vi> up;
int st[mxN], fin[mxN], sta[mxN];
int num = 0, l = 1;

void dfs(int cur, int prev = 0){
	st[cur] = num++;
	up[cur][0] = prev;
	repn(i, 1, l + 1) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for(int x : g[cur]) if(x != prev) dfs(x, cur);
	fin[cur] = num++;
}

bool upper(int a, int b){
	return st[a] <= st[b] && fin[a] >= fin[b];
}

int lca(int a, int b){
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	for(int i = l; i >= 0; i--) if(!upper(up[a][i], b)) a = up[a][i];
	return up[a][0];
}

map<pi, int> ind;

void dfs1(int cur, int prev){
	for(int x : g[cur]) if(x != prev){
		dfs1(x, cur);
		sta[cur] += sta[x];
	}
	if(sta[cur] >= (2 * k) && prev != -1) ans.pb(ind[mp(cur, prev)]);
}

bool cmp(int a, int b){
	return st[a] > st[b];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		ind[mp(a, b)] = ind[mp(b, a)] = i;
		g[a].pb(b);
		g[b].pb(a);
	}
	up.resize(n + 1);
	while((1 << l) <= n) l++;
	rep(i, n) up[i].resize(l + 1);
	dfs(0);
	rep(i, m){
		int s;
		cin >> s;
		vi nw(s);
		rep(j, s){
			cin >> nw[j];
			nw[j]--;
		}
		sort(all(nw), cmp);
		rep(j, s){
			int a = nw[j], b = nw[(j + 1) % s];
			int c = lca(a, b);
			sta[a]++, sta[b]++;
			sta[c] -= 2;
		}
	}
	dfs1(0, -1);
	cout << (int)(ans.size()) << endl;
	sort(all(ans));
	for(int x : ans) cout << x + 1 << " ";
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
