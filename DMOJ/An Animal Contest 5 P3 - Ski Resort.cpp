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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
int s[mxN], d[mxN];
vector<pi> g[mxN];

bool cmp(pi a, pi b){
	return a.se < b.se;
}

void dfs(int cur, int l, int r){
	if(r < l) return;
	if(!(int)(g[cur].size())){
		d[cur] = r - l + 1;
		return;
	}
	int bst = 1e9 + 10, st = -1;
	for(int i = 0; i < (int)(g[cur].size()); i++){
		if(abs(g[cur][i].se - s[l]) >= bst){
			st = i - 1;
			break;
		}
		bst = min(bst, abs(g[cur][i].se - s[l]));
	}
	if(st == -1) st = (int)(g[cur].size()) - 1;
	repn(i, st, (int)(g[cur].size())){
		if(l > r) continue;
		int l1 = l, r1 = r;
		if(i != (int)(g[cur].size()) - 1){
			while(l1 < r1){
				int mid = (l1 + r1 + 1) / 2;
				if(abs(g[cur][i + 1].se - s[mid]) >= abs(g[cur][i].se - s[mid])) l1 = mid;
				else r1 = mid - 1;
			}
			if(abs(g[cur][i + 1].se - s[l1]) < abs(g[cur][i].se - s[l1])) l1--;
		}
		else l1 = r;
		if(l <= l1){
			dfs(g[cur][i].fi, l, l1);
			d[cur] += d[g[cur][i].fi];
			l = l1 + 1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	rep(i, n - 1){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		g[a].pb(mp(b, c));
	}
	rep(i, k) cin >> s[i];
	sort(s, s + k);
	rep(i, n) sort(all(g[i]), cmp);
	dfs(0, 0, k - 1);
	rep(i, n) cout << d[i] << " \n"[i == (n - 1)];
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
