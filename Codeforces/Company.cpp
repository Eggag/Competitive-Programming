#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int logn = 22;
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int lc[logn][mxN];
int up[logn][mxN];
int st[mxN], en[mxN];
int d[mxN];
int cnt = 0;

void dfs(int cur, int prev, int de = 0){
	d[cur] = de;
	st[cur] = cnt++;
	up[0][cur] = prev;
	repn(i, 1, logn) up[i][cur] = up[i - 1][up[i - 1][cur]];
	for(int x : g[cur]) if(x != prev) dfs(x, cur, de + 1);
	en[cur] = cnt++;
}

bool upper(int a, int b){
	return (st[a] <= st[b] && en[a] >= en[b]);
}

int lca(int a, int b){
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	int c = a;
	for(int i = logn - 1; i >= 0; i--) if(!upper(up[i][c], b)) c = up[i][c];
	return up[0][c];
}

int LCA(int l, int r){ // [l; r)
	int t = __lg(r - l);
	return lca(lc[t][l], lc[t][r - (1 << t)]);
}

int dat[1 << 21], dat1[1 << 21];
int sz;

int cmbmin(int a, int b){
	if(a == -1 && b == -1) return -1;
	if(a == -1) return b;
	else if(b == -1) return a;
	else return (en[a] < en[b] ? a : b);
}

int cmbmax(int a, int b){
	if(a == -1 && b == -1) return -1;
	if(a == -1) return b;
	else if(b == -1) return a;
	else return (st[a] > st[b] ? a : b);
}

void update(int i, int s, int e){
	if(s == e){
		dat[i] = s;
		dat1[i] = s;
		return;
	}
	int m = (s + e) / 2;
	update(i << 1, s, m);
	update(i << 1 | 1, m + 1, e);
	dat[i] = cmbmin(dat[i << 1], dat[i << 1 | 1]);
	dat1[i] = cmbmax(dat1[i << 1], dat1[i << 1 | 1]);
}

int minQ(int i, int s, int e, int x, int y){
	if(e < x || y < s) return -1;
	if(x <= s && e <= y) return dat[i];
	int m = (s + e) / 2;
	return cmbmin(minQ(i << 1, s, m, x, y), minQ(i << 1 | 1, m + 1, e, x, y));
}
int minQ(int x, int y){
	return minQ(1, 0, sz, x, y);
}

int maxQ(int i, int s, int e, int x, int y){
	if(e < x || y < s) return -1;
	if(x <= s && e <= y) return dat1[i];
	int m = (s + e) / 2;
	return cmbmax(maxQ(i << 1, s, m, x, y), maxQ(i << 1 | 1, m + 1, e, x, y));
}

int maxQ(int x, int y){
	return maxQ(1, 0, sz, x, y);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	repn(i, 1, n){
		int p;
		cin >> p;
		g[p - 1].pb(i);
	}
	dfs(0, 0);
	rep(i, n) lc[0][i] = i;
	for(int l = 0; l < logn - 1; l++){
		for(int i = 0; i + (2 << l) <= n; i++){
			lc[l + 1][i] = lca(lc[l][i], lc[l][i + (1 << l)]);
		}
	}
	sz = n + 1;
	update(1, 0, sz);
	rep(i, q){
		int l, r;
		cin >> l >> r;
		l--, r--;
		int c = LCA(l, r + 1);
		if(c >= l && c <= r){
			pi bst = mp(c + 1, d[c]);
			int c1 = lca(LCA(l, c), LCA(c + 1, r + 1));
			if(c == r) c1 = LCA(l, c);
			if(c == l) c1 = LCA(c + 1, r + 1);
			if(d[c1] > bst.se) bst = mp(c + 1, d[c1]);
			cout << bst.fi << " " << bst.se << '\n';
		}
		else{
			pi bst = mp(c + 1, d[c]);
			for(int x : {l, l + 1}){
				int dist = d[x] - d[c] - 1;
				int nd = x;
				rep(j, logn) if(dist & (1 << j)) nd = up[j][nd];
				int mnInd = minQ(l, r), mxInd = maxQ(l, r);
				if(mnInd != -1 && en[mnInd] < st[nd]){
					int c1 = lca(LCA(l, mnInd), LCA(mnInd + 1, r + 1));
					if(mnInd == r) c1 = LCA(l, mnInd);
					if(mnInd == l) c1 = LCA(mnInd + 1, r + 1);
					if(d[c1] >= bst.se) bst = mp(mnInd + 1, d[c1]);
				}
				else if(mxInd != -1 && st[mxInd] > en[nd]){
					int c1 = lca(LCA(l, mxInd), LCA(mxInd + 1, r + 1));
					if(mxInd == r) c1 = LCA(l, mxInd);
					if(mxInd == l) c1 = LCA(mxInd + 1, r + 1);
					if(d[c1] >= bst.se) bst = mp(mxInd + 1, d[c1]);
				}
			}
			cout << bst.fi << " " << bst.se << '\n';
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
