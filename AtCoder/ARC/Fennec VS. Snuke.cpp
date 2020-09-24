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

vi g[100005];
int d[100005], d1[100005];

void dfs(int cur, int prev){
	if(prev == -1) d[cur] = 0;
	else d[cur] = d[prev] + 1;
	for(int u : g[cur]) if(u != prev) dfs(u, cur);
}

void dfs1(int cur, int prev){
	if(prev == -1) d1[cur] = 0;
	else d1[cur] = d1[prev] + 1;
	for(int u : g[cur]) if(u != prev) dfs1(u, cur);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(d, 0, sizeof(d));
	memset(d1, 0, sizeof(d1));
	dfs(0, -1);
	dfs1(n - 1, -1);
	int ans = 0;
	rep(i, n) if(d[i] <= d1[i]) ans++;
	if(ans <= (n - ans)) cout << "Snuke" << endl;
	else cout << "Fennec" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
