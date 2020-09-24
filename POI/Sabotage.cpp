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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
vi g[mxN];
int f = 1;
ld g1 = 0.0;
int d[mxN], gd[mxN];

void dfs(int cur, int prev){
	d[cur] = 1;
	for(int u : g[cur]) if(u != prev){
		dfs(u, cur);
		d[cur] += d[u];
	}
	for(int u : g[cur]) if(u != prev){
		if(gd[u]){
			ld dn = (ld)((ld)(d[u]) / (ld)(d[cur] - 1));
			if(dn >= g1) gd[cur] = 1;
		}
	}
	ld dn = -1.0;
	if(d[cur] > 1) dn = (ld)((ld)(1.0) / (ld)(d[cur] - 1));
	if(dn >= g1) gd[cur] = 1;
	if(gd[cur] && d[cur] > k) f = 1;
}

bool check(ld g){
	memset(d, 0, sizeof(d));
	memset(gd, 0, sizeof(gd));
	f = 0;
	g1 = g;
	dfs(0, -1);
	return f;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	repn(i, 1, n){
		int x;
		cin >> x;
		x--;
		g[i].pb(x);
		g[x].pb(i);
	}
	ld l = 0.0, r = 1.0;
	while(abs(l - r) > 1e-8){
		ld mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << fixed << setprecision(10) << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
