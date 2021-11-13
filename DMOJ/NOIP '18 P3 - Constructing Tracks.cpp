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
const int mxN = 5e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> g[mxN];
int n, m, cr;
pi dp[mxN];

bool gr(pi a, pi b){
	return a.se > b.se;
}

bool gr1(pi a, pi b){
	if(a.fi != b.fi) return a.fi > b.fi;
	return a.se > b.se;
}

void dfs(int cur, int prev = -1, int ed = 0){
	dp[cur] = mp(0, ed);
	vector<pi> nw;
	int tot = 0;
	for(pi x : g[cur]) if(x.fi != prev){
		dfs(x.fi, cur, x.se);
		nw.pb(dp[x.fi]);
		tot += dp[x.fi].fi;
	}
	sort(all(nw), gr);
	int l = 0, r = (int)(nw.size()) - 1;
	int uwu = 0;
	while(l < r){
		if(nw[l].se + nw[r].se >= cr) uwu++, l++, r--;
		else r--;
	}
	if(ed >= cr){
                if(gr1(mp(tot + uwu + 1, 0), dp[cur])) dp[cur] = mp(tot + uwu + 1, 0);
        }
        else if(nw.size()){
                int le = 0, ri = (int)(nw.size()) - 1;
                if(gr1(mp(tot + uwu, ed), dp[cur])) dp[cur] = mp(tot + uwu, ed);
                while(le < ri){
                        int mid = (le + ri) / 2;
                        int l1 = 0, r1 = (int)(nw.size()) - 1;
                        int owo = 0, f = 1;
                        while(l1 < r1){
                                if(f && r1 == mid){
                                        r1--, f = 0;
                                        continue;
                                }
                                if(f && l1 == mid){
                                        l1++, f = 0;
                                        continue;
                                }
                                if(nw[l1].se + nw[r1].se >= cr) owo++, l1++, r1--;
                                else r1--;
                        }
                        if(l1 == r1 && f && l1 == mid) f = 0;
                        if(uwu == owo && !f) ri = mid;
                        else le = mid + 1;
                }
                int l1 = 0, r1 = (int)(nw.size()) - 1;
                int owo = 0, f = 1;
                while(l1 < r1){
                        if(f && r1 == le){
                                r1--, f = 0;
                                continue;
                        }
                        if(f && l1 == le){
                                l1++, f = 0;
                                continue;
                        }
                        if(nw[l1].se + nw[r1].se >= cr) owo++, l1++, r1--;
                        else r1--;
                }
                if(l1 == r1 && f && l1 == le) f = 0;
                if(uwu == owo && !f){
                        int mx = nw[le].se;
                        if(mx + ed >= cr){
                                if(gr1(mp(tot + uwu + 1, 0), dp[cur])) dp[cur] = mp(tot + uwu + 1, 0);
                        }
                        else if(gr1(mp(tot + uwu, mx + ed), dp[cur])) dp[cur] = mp(tot + uwu, mx + ed);
                }
        }
}

bool check(int ge){
	cr = ge;
	dfs(0, -1);
	return dp[0].fi >= m;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	int tot = 0;
	rep(i, n - 1){
		int a, b, l;
		cin >> a >> b >> l;
		a--, b--;
		g[a].pb(mp(b, l));
		g[b].pb(mp(a, l));
		tot += l;
	}
	int l = 0, r = tot;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
