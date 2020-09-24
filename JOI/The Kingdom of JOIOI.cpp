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
const int mxN = 2005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int h, w;
int g[mxN][mxN];
int mn[mxN][mxN], mn1[mxN][mxN];
int mx[mxN][mxN], mx1[mxN][mxN];
pi bst;

int solve(){
	//compute all the mins and maxes
	//mn and mx are for top
	//mn1 and mx1 are for bottom
	rep(j, w){
		mn[0][j] = g[0][j];
		mx[0][j] = g[0][j];
		repn(i, 1, h){
			mn[i][j] = min(mn[i - 1][j], g[i][j]);
			mx[i][j] = max(mx[i - 1][j], g[i][j]);
		}
	}
	rep(j, w){
		mn1[h - 1][j] = g[h - 1][j];
		mx1[h - 1][j] = g[h - 1][j];
		for(int i = h - 2; i >= 0; i--){
			mn1[i][j] = min(mn1[i + 1][j], g[i][j]);
			mx1[i][j] = max(mx1[i + 1][j], g[i][j]);
		}
	}
	int ans = 2e9;
	vi lev(w, h);
	rep(i, bst.se + 1) lev[i] = bst.fi;
	int maxEl = 0;
	for(int i = h - 1; i >= bst.fi; i--){
		rep(j, bst.se + 1) maxEl = max(maxEl, g[i][j]);
	}
	//now we do the initial extension
	int mx2 = 0, mx3 = 0;
	int mn2 = 2e9, mn3 = 2e9;
	while(lev[0] > 0 && g[lev[0] - 1][0] <= maxEl) lev[0]--;
	repn(i, 1, w){
		 while(lev[i] > 0 && lev[i] > lev[i - 1] && g[lev[i] - 1][i] <= maxEl){
		 	lev[i]--;
		 }
	}
	rep(j, w){
		if(lev[j] != h){
			mx2 = max(mx2, mx1[lev[j]][j]);
			mn2 = min(mn2, mn1[lev[j]][j]);
		}
		if(lev[j]){
			mx3 = max(mx3, mx[lev[j] - 1][j]);
			mn3 = min(mn3, mn[lev[j] - 1][j]);
		}
	}
	ans = min(ans, max(mx3 - mn3, mx2 - mn2));
	int cur = 0;
	while(true){
		//move the pointer if we finished the last col
		while(cur < w && !lev[cur]) cur++;
		if(cur == w) break;
		int mnxt = 2e9;
		rep(j, w){
			if(lev[j] && (!j || (j && lev[j] > lev[j - 1]))){
				mnxt = min(mnxt, g[lev[j] - 1][j]);
			}
		}
		maxEl = max(maxEl, mnxt);
		int mx2 = 0, mx3 = 0;
		int mn2 = 2e9, mn3 = 2e9;
		while(lev[0] > 0 && g[lev[0] - 1][0] <= maxEl) lev[0]--;
		repn(i, 1, w){
			 while(lev[i] > 0 && lev[i] > lev[i - 1] && g[lev[i] - 1][i] <= maxEl){
			 	lev[i]--;
				if(cur == (w - 1) && i == (w - 1)) break;
			 }
		}
		if(cur == (w - 1) && !lev[cur]) break;
		rep(j, w){
			if(lev[j] != h){
				mx2 = max(mx2, mx1[lev[j]][j]);
				mn2 = min(mn2, mn1[lev[j]][j]);
			}
			if(lev[j]){
				mx3 = max(mx3, mx[min(h - 1, lev[j] - 1)][j]);
				mn3 = min(mn3, mn[min(h - 1, lev[j] - 1)][j]);
			}
		}
		//update answer
		ans = min(ans, max(mx3 - mn3, mx2 - mn2));
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> h >> w;
	rep(i, h) rep(j, w) cin >> g[i][j];
	int mn0 = 2e9;
	rep(i, h) rep(j, w) if(g[i][j] < mn0){
		mn0 = g[i][j];
		bst = mp(i, j);
	}
	int ans = solve();
	bst = {h - 1 - bst.fi, bst.se};
	rep(i, h / 2) rep(j, w) swap(g[i][j], g[h - i - 1][j]);
	ans = min(ans, solve());
	bst = {bst.fi, w - 1 - bst.se};
	rep(i, h) rep(j, w / 2) swap(g[i][j], g[i][w - j - 1]);
	ans = min(ans, solve());
	rep(i, h / 2) rep(j, w) swap(g[i][j], g[h - i - 1][j]);
	bst = {h - 1 - bst.fi, bst.se};
	ans = min(ans, solve());
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
