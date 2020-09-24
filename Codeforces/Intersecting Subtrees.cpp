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

int query(char c, int nd){
	cout << c << " " << nd + 1 << endl;
	int ret;
	cin >> ret;
	return (ret - 1);
}

int ans;
int vs[1005], vs1[1005];
vi g[1005];

void dfs(int cur, int prev){
	if(vs[cur]){
		//check if this is also a yellow
		int q = query('A', cur);
		if(vs1[q]) ans = cur + 1;
		return; //we don't continue from it
	}
	for(int x : g[cur]) if(x != prev) dfs(x, cur);
}

void solve(){
	int n;
	cin >> n;
	ans = -1;
	rep(i, n) g[i].clear();
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	int k1;
	cin >> k1;
	vi x(k1);
	memset(vs, 0, sizeof(vs));
	memset(vs1, 0, sizeof(vs1));
	rep(i, k1) cin >> x[i], x[i]--, vs[x[i]] = 1;
	int k2;
	cin >> k2;
	vi y(k2);
	rep(i, k2) cin >> y[i], y[i]--, vs1[y[i]] = 1;
	int q = query('B', y[0]);
	if(vs[q]){ //the node we asked happens to be a green
		cout << "C " << q + 1 << endl;
		return;
	}
	dfs(q, -1);
	cout << "C " << ans << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
