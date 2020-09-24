#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include "library.h"
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

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

int pos[mxN][mxN];
vi g[mxN];

void Solve(int n){
	if(n == 1){
		vi ans = {1};
		Answer(ans);
		return;
	}
	int sz = n / 31; //the size of our guess bucket
	int num = (n * (n - 1)) / 2;
	int rem = 20000;
	memset(pos, -1, sizeof(pos));
	while(num > rem){
		vi vis(n, 0), cr;
		rep(k, sz){
			while(true){
				int ind = rng() % n;
				if(!vis[ind]){
					vis[ind] = 1;
					cr.pb(ind);
					break;
				}
			}
		}
		int ans = Query(vis);
		if(ans == sz){
			rep(i, cr.size()) rep(j, cr.size()) if(i != j && pos[cr[i]][cr[j]] == -1){
				num--;
				pos[cr[i]][cr[j]] = 0;
				pos[cr[j]][cr[i]] = 0;
			}		
		}
		rem--;
	}
	vi nw(n, 0);
	pi prev = {-1, -1};
	rep(i, n) rep(j, n) if(i != j && pos[i][j] == -1){
		if(prev.fi != -1) nw[prev.fi] = nw[prev.se] = 0;
		nw[i] = nw[j] = 1;
		prev = mp(i, j);
		int ans = Query(nw);
		if(ans == 1) pos[i][j] = pos[j][i] = 1;
		else pos[i][j] = pos[j][i] = 0;
	}
	//now we know all the comparisons so we can just reconstruct the answer
	int st = -1;
	rep(i, n){
		rep(j, n){
			if(pos[i][j] == 1) g[i].pb(j);
		}
		if(g[i].size() == 1) st = i;
	}
	vi ans;
	ans.pb(st + 1);
	int nxt = g[st][0];
	repn(i, 1, n){
		ans.pb(nxt + 1);
		rep(j, g[nxt].size()){
			if((ans[(int)ans.size() - 2] - 1) != g[nxt][j]){
				nxt = g[nxt][j];
				break;
			}
		}
	}
	Answer(ans);
	return;
}
