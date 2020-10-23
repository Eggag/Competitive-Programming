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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ll k;
vi g[mxN];
int a[mxN];
pi dp[mxN];

bool cmp(pi l, pi r){
	if(l.fi != r.fi) return l.fi > r.fi;
	return l.se < r.se;
}

void dfs(int cur, int prev){
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		if((dp[x].fi - 1) == dp[cur].fi) dp[cur].se = min(dp[cur].se, dp[x].se);
		if((dp[x].fi - 1) > dp[cur].fi) dp[cur] = mp(dp[x].fi - 1, dp[x].se);
		if((a[x] - 1) == dp[cur].fi) dp[cur].se = min(dp[cur].se, x);
		if((a[x] - 1) > dp[cur].fi) dp[cur] = mp(a[x] - 1, x);
	}
}

void dfs1(int cur, int prev, pi bst = {-1e9, 1e9}){
	bst.fi--;
	if(cmp(bst, dp[cur])) dp[cur] = bst;
	//now we update bst with the thing we are currently on
	pi nw = {a[cur], cur};
	if(cmp(nw, bst)) bst = nw;
	pi mx = {-1e9, 1e9}, mx1 = {-1e9, 1e9};
	int ind = -1, ind1 = -1;
	int cnt = 0;
	for(int x : g[cur]) if(x != prev){
		pi dpa = dp[x];
		dpa.fi--;
		pi mb = {a[x] - 1, x};
		if(cmp(mb, dpa)) dpa = mb;
		if(cmp(dpa, mx) && dpa.se != 1e9){
			mx1 = mx;
			mx = dpa;
			ind1 = ind;
			ind = cnt;
		}
		else if(dpa.se != 1e9){
			if(cmp(dpa, mx1)){
				mx1 = dpa;
				ind1 = cnt;
			}
		}
		cnt++;
	}
	cnt = 0;
	for(int x : g[cur]) if(x != prev){
		if(ind != -1 && cnt != ind){
			//improve bst before sending
			pi bst1 = bst;
			if(cmp(mx, bst1)) bst1 = mx;
			dfs1(x, cur, bst1);
		}
		else if(ind1 != -1 && cnt != ind1){
			//use mx1 to improve bst
			pi bst1 = bst;
			if(cmp(mx1, bst1)) bst1 = mx1;
			dfs1(x, cur, bst1);
		}
		else dfs1(x, cur, bst);
		cnt++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	k++;
	rep(i, n) cin >> a[i];
	rep(i, n - 1){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	rep(i, n) dp[i] = {-1e9, 1e9};
	dfs(0, -1);
	dfs1(0, -1);
	vector<ll> b(n), vis(n, 0);
	rep(i, n) b[i] = dp[i].se;
	ll cnt = 1, cur = 0, pr = -1;
	while(true){
		if(cnt == k){
			cout << cur + 1 << endl;
			return 0;
		}
		if(vis[cur]){
			ll len = cnt - vis[cur]; //the length of the cycle
			k -= vis[cur] - 1;
			k %= len;
			rep(i, k) pr = b[pr];
			cout << pr + 1 << endl;
			return 0;
		}
		vis[cur] = cnt;
		pr = cur;
		cur = b[cur];
		cnt++;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
