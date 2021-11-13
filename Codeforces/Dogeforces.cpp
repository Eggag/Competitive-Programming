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
const int mxN = 505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int g[mxN][mxN];
int num = 0;
int cnt = 0;
int ans[mxN * mxN];
vector<pi> ed;

void dfs(vi cur, int prev = -1){
	int mx = 0;
	rep(j, cur.size()) rep(k, cur.size()) mx = max(mx, g[cur[j]][cur[k]]);
	int ind = cnt;
	if((int)(cur.size()) == 1){
		ans[cur[0]] = mx;
		ind = cur[0];
	}
	else ans[cnt] = mx;
	num++;
	if(prev != -1) ed.pb(mp(ind, prev));
	if((int)(cur.size()) == 1) return;
	cnt++;
	int pr = ind;
	while(cur.size()){
		vi a = {cur[0]}, b;
		repn(i, 1, cur.size()){
			if(g[cur[i]][cur[0]] == mx) b.pb(cur[i]);
			else a.pb(cur[i]);
		}
		swap(cur, b);
		dfs(a, pr);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) rep(j, n) cin >> g[i][j];
	vi cur;
	rep(i, n) cur.pb(i);
	cnt = n;
	dfs(cur);
	cout << num << '\n';
	rep(i, num) cout << ans[i] << ' ';
	cout << '\n';
	cout << n + 1 << '\n';
	for(pi x : ed) cout << x.fi + 1 << ' ' << x.se + 1 << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
