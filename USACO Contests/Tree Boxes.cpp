#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "grader.h"
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

int n, q;
vi g[mxN];
vector<vi> up;
int st[mxN], fin[mxN], sta[mxN];
int num = 0, l = 1;

void addRoad(int a, int b){
	g[a].pb(b);
	g[b].pb(a);
}

void dfs0(int cur, int prev = 0){
	st[cur] = num++;
	up[cur][0] = prev;
	repn(i, 1, l + 1) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for(int x : g[cur]) if(x != prev) dfs0(x, cur);
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

int y = 1, z;
pi pos[mxN];
int d[mxN];

void dfs(int cur, int prev, int de){
	d[cur] = de;
	pos[cur].fi = y++;
	for(int x : g[cur]) if(x != prev) dfs(x, cur, de + 1);
	pos[cur].se = z--;
}

void buildFarms(){
	n = getN();	
	q = getQ();	
	z = n;
	dfs(0, -1, 0);
	rep(i, n) setFarmLocation(i, pos[i].fi, pos[i].se);
	up.resize(n + 1);
	while((1 << l) <= n) l++;
	rep(i, n) up[i].resize(l + 1);
	dfs0(0);	
	return;
}

void notifyFJ(int a, int b){
	rep(i, 2){
		if(upper(a, b)){
			int mnX = min(pos[a].fi, pos[b].fi);
			int mxX = max(pos[a].fi, pos[b].fi);
			int mnY = min(pos[a].se, pos[b].se);
			int mxY = max(pos[a].se, pos[b].se);
			addBox(mnX, mnY, mxX, mxY);
			return;	
		}
		swap(a, b);
	}
	int c = lca(a, b);
	int mnX = min(pos[a].fi, pos[c].fi);
	int mxX = max(pos[a].fi, pos[c].fi);
	int mnY = min(pos[a].se, pos[c].se);
	int mxY = max(pos[a].se, pos[c].se);
	addBox(mnX, mnY, mxX, mxY);
	int c1 = b;
	int dist = d[b] - d[c] - 1;
	for(int i = l; i >= 0; i--) if(dist & (1 << i)) c1 = up[c1][i];
	mnX = min(pos[b].fi, pos[c1].fi);
	mxX = max(pos[b].fi, pos[c1].fi);
	mnY = min(pos[b].se, pos[c1].se);
	mxY = max(pos[b].se, pos[c1].se);
	addBox(mnX, mnY, mxX, mxY);
	return;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
