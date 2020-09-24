#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "supertrees.h"
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
const int mxN = 1005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> g[mxN];
int vis[mxN];
vi cur1, cur2;

void dfs2(int cur){
	vis[cur] = 1;
	cur2.pb(cur);
	for(pi x : g[cur]) if(x.se == 2 && !vis[x.fi]) dfs2(x.fi);
}

void dfs1(int cur){
	vis[cur] = 1;
	cur1.pb(cur);
	for(pi x : g[cur]) if(x.se == 1 && !vis[x.fi]) dfs1(x.fi);
}

int construct(vector<vi> p) {
	int n = p.size();
	vector<vi> ans(n);
	rep(i, n) ans[i].resize(n);
	rep(i, n) rep(j, n) ans[i][j] = 0;
	int mx = 0;
	rep(i, n) rep(j, n) if(p[i][j] && i != j){
		g[i].pb({j, p[i][j]});
		mx = max(mx, p[i][j]);
	}
	if(mx == 3) return 0;
	rep(i, n) if(!vis[i]){
		int f = 0;
		for(pi x : g[i]) if(x.se == 2) f |= 2;
		if(f == 2){
			cur2.clear();
			dfs2(i);
			vi circ; // the arc
			vi vis1((int)cur2.size(), 0);
			rep(j, cur2.size()) if(!vis1[j]){
				int cr = cur2[j];
				circ.pb(cr);
				vi ch = {cr};
				vis1[j] = 2;
				rep(k, cur2.size()) if(j != k && !vis1[k]){
					if(!p[cur2[j]][cur2[k]]) return 0;
					if(p[cur2[j]][cur2[k]] == 1){
						vis1[k] = 2;
						ans[cr][cur2[k]] = 1;
						ans[cur2[k]][cr] = 1;
						ch.pb(cur2[k]);
					}
				}
				rep(l, ch.size()){
					rep(k, cur2.size()) if(vis1[k] != 2){
						if(p[ch[l]][cur2[k]] != 2) return 0;
					}
				}
				rep(k, cur2.size()) if(vis1[k] == 2) vis1[k] = 1;
			}
			if(circ.size() < 3) return 0;
			rep(j, circ.size() - 1){
				ans[circ[j]][circ[j + 1]] = 1;
				ans[circ[j + 1]][circ[j]] = 1;
			}
			int m = (int)circ.size() - 1;
			ans[circ[0]][circ[m]] = 1;
			ans[circ[m]][circ[0]] = 1;
		}
	}
	rep(i, n) if(!vis[i]){
		int f = 0;
		for(pi x : g[i]){
			if(x.se == 1) f |= 1;
			if(x.se == 2) f |= 2;
		}
		if(f == 1){
			cur1.clear();
			dfs1(i);
			rep(j, cur1.size()) rep(k, cur1.size()) if(j != k){
				if(p[cur1[j]][cur1[k]] != 1) return 0;
			}
			sort(all(cur1));
			rep(j, cur1.size() - 1){
				ans[cur1[j]][cur1[j + 1]] = 1;
				ans[cur1[j + 1]][cur1[j]] = 1;
			}
		}
	}
	build(ans);
	return 1;
}
