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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vector<pi> g[105];
int know[105];

bool cmp(pi a, pi b){
	return a.fi < b.fi;
}

void solve(){
	int c, d;
	cin >> c >> d;
	vector<pi> x(c);
	repn(i, 1, c) cin >> x[i].fi, x[i].se = i, x[i].fi = abs(x[i].fi);
	rep(i, 105) g[i].clear();
	sort(1 + all(x), cmp);
	vi ans(d, 1e6 - 10);
	rep(i, d){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[v].pb(mp(u, i));
		g[u].pb(mp(v, i));
	}
	rep(i, 105) know[i] = -1;
	know[0] = 0;
	int last = 0;
	repn(i, 1, c){
		int mn = 1e9;
		int bst = -1;
		for(pi j : g[x[i].se]){
			int a = j.fi; //the vertex
			int b = j.se; //the index
			if(know[a] != -1){
				if(know[a] < mn){
					mn = know[a];
					bst = b;
				}
			}
		}
		if(bst != -1){
			int need = last;
			if(i == 1 || (i > 1 && x[i].fi != x[i - 1].fi)) need++;
			ans[bst] = max(0, need - mn), last = mn + ans[bst];
			know[x[i].se] = mn + ans[bst];
		}
	}
	rep(i, d){
		int res = ans[i];
		cout << res;
		if(i != (d - 1)) cout << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
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
