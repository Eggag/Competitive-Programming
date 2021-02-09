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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll w[mxN];
int deg[mxN], le[mxN];
vi g[mxN];

bool cmp(int a, int b){
	return w[a] > w[b];
}

void dfs(int cur, int prev){
	int f = 0;
	if(prev != -1) deg[prev]++;
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur);
		f = 1;
	}
	le[cur] = !f;
}

void solve(){
	int n;
	cin >> n;
	ll tot = 0LL;
	rep(i, n) cin >> w[i], tot += w[i], deg[i] = 0, le[i] = 0, g[i].clear();
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	vi x(n);
	rep(i, n) x[i] = i;
	sort(all(x), cmp);
	deg[0]--;
	cout << tot << " ";
	int cnt = 1;
	rep(i, n){
		while(deg[x[i]]){
			if(cnt == (n - 1)) goto en;
			tot += w[x[i]];
			cout << tot << " ";
			cnt++;
			deg[x[i]]--;
		}	
	}
	en:;
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
