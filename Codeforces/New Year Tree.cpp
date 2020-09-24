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
const int mxN = 4e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
int c[mxN];
int st[mxN], en[mxN];
int tt = 0;
vi g[mxN];

ll t[4 * mxN], lazy[4 * mxN];

void push(int i){
	t[i * 2 + 1] = lazy[i];
	t[i * 2 + 2] = lazy[i];
	lazy[i * 2 + 1] = lazy[i];
	lazy[i * 2 + 2] = lazy[i];
	lazy[i] = 0;
}

void upd(int l, int r, int x, int v = 0, int tl = 0, int tr = n) {
	if(r <= tl || tr <= l) return;
	if(l <= tl && tr <= r){
		t[v] = (1LL << x);
		lazy[v] = t[v];
		return;
	}
	if(lazy[v]) push(v);
	int mid = (tl + tr) >> 1;
	upd(l, r, x, v * 2 + 1, tl, mid);
	upd(l, r, x, v * 2 + 2, mid, tr);
	t[v] = t[v * 2 + 1] | t[v * 2 + 2];
}

ll qry(int l, int r, int v = 0, int tl = 0, int tr = n){
	if(r <= tl || tr <= l) return 0;
	if(l <= tl && tr <= r) return t[v];
	if(lazy[v]) push(v);
	int mid = (tl + tr) >> 1;
	return qry(l, r, v * 2 + 1, tl, mid) | qry(l, r, v * 2 + 2, mid, tr);
}

void dfs(int cur, int p = -1){
	st[cur] = tt++;
	upd(st[cur], st[cur] + 1, c[cur]);
	for(int x : g[cur]) if(x != p){
		dfs(x, cur);
	}
	en[cur] = tt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> c[i];
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0);
	rep(i, m){
		int tp;
		cin >> tp;
		if(tp == 1){
			int v, c;
			cin >> v >> c;
			v--;
			upd(st[v], en[v], c);
		}
		else{
			int v;
			cin >> v;
			v--;
			cout << (__builtin_popcountll(qry(st[v], en[v]))) << endl;
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
