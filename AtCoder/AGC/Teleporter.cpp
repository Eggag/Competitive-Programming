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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k, ans = 0;
int a[mxN], sb[mxN];
vi g[mxN];

void dfs(int cur, int prev){
	sb[cur] = 1;
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		sb[cur] = max(sb[cur], sb[x] + 1);
	}
	if(cur && a[cur] && sb[cur] == k) ans++, sb[cur] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	rep(i, n) cin >> a[i], a[i]--;
	if(a[0]) a[0] = 0, ans++;
	repn(i, 1, n){
		g[i].pb(a[i]);
		g[a[i]].pb(i);
	}
	dfs(0, -1);
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
