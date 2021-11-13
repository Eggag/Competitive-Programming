#include <bits/stdc++.h>
#include "swaps.h"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define debug(x) cerr << #x << " " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int mxN = 505;

int cm[mxN][mxN];

bool cmp(int a, int b){
	return cm[a][b];
}

void solve(int n, int V){
	vector<pi> c;
	repn(i, 1, n + 1) repn(j, i + 1, n + 1) c.pb(mp(i, j));
	rep(i, mxN) cm[i][i] = 0;
	int nm = 0;
	int m = c.size();
	vi vis(m, 0);
	rep(i, V){
		if(nm == m) break;
		vi nw(n + 1, 0);
		vector<pi> cr;
		rep(j, m) if(!vis[j]){
			if(!nw[c[j].fi] && !nw[c[j].se]){
				vis[j] = 1;
				nm++;
				nw[c[j].fi] = nw[c[j].se] = 1;
				schedule(c[j].fi, c[j].se);
				cr.pb(c[j]);
			}
		}
		vi res = visit();
		rep(j, res.size()){
			cm[cr[j].fi][cr[j].se] = res[j];
			cm[cr[j].se][cr[j].fi] = !res[j];
		}
	}
	vi x;
	rep(i, n) x.pb(i + 1);
	sort(all(x), cmp);
	answer(x);
}
