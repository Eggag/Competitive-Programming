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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> g[mxN];
set<pi> dp[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	vector<pi> a;
	rep(i, q){
		int t;
		cin >> t;
		if(t == 1){
			int x;
			cin >> x;
			a.pb(mp(i, x));
		}
		else{
			int x, y;
			cin >> x >> y;
			g[x].pb(mp(i, y));
		}
	}
	vi ans;
	rep(i, a.size()){
		pi nw = a[i];
		vector<pi> owo = {nw};
		while(true){
			//check dp?
			auto ite = dp[nw.se].lb(mp(nw.fi, 0));
			if(ite != dp[nw.se].end()){
				pi an = *ite;
				auto it = lb(all(g[nw.se]), mp(nw.fi + 1, 0));
				if(it == g[nw.se].end() || (*it).fi > an.fi){
					nw = an;
					goto fn;			
				}
			}
			if(ite != dp[nw.se].begin()){
				ite--;
				pi an = *ite;
				auto it = lb(all(g[nw.se]), mp(an.fi + 1, 0));
				if(it == g[nw.se].end() || (*it).fi > nw.fi){
					nw = an;
					goto fn;			
				}
			}
			//no dp, add dp
			auto it = lb(all(g[nw.se]), mp(nw.fi + 1, 0));
			if(it == g[nw.se].end()) break;
			nw = *it;
			owo.pb(nw);
		}
		fn:;
		for(pi x : owo) dp[x.se].insert(mp(x.fi, nw.se));
		ans.pb(nw.se);
	}
	for(int x : ans) cout << x << ' ';
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
