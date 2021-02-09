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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool cmp(pair<int, pi> a, pair<int, pi> b){
	return a.fi > b.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi d(n);
	vector<pair<int, pi>> ed;
	rep(i, n) cin >> d[i], ed.pb(mp(d[i], mp(2 * i + 1, 2 * (i + 1))));
	sort(all(ed), cmp);
	vector<pi> ans;
	repn(i, 1, n) ans.pb(mp(ed[i - 1].se.fi, ed[i].se.fi));
	vector<vi> nm(n);
	rep(i, n) nm[i].pb(ed[i].se.fi);
	rep(i, n){
		int nxt = i + (ed[i].fi - 1);
		if((i + (ed[i].fi - 1)) < n){
			ans.pb(mp(nm[nxt][0], ed[i].se.se));
			if((int)(nm[nxt].size()) == 1) nm[nxt].pb(ed[i].se.se);
		}
		else{
			int d = (i + (ed[i].fi - 1)) - n + 1;
			ans.pb(mp(nm[n - 1][d], ed[i].se.se));
			if((int)(nm[n - 1].size()) == (d + 1)) nm[n - 1].pb(ed[i].se.se);
		}
	}
	rep(i, 2 * n - 1) cout << ans[i].fi << " " << ans[i].se << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
