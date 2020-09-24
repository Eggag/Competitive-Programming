#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[100005];
int c[100005];
int v[100005];


void dfs(int cur, int prev, int col){
	v[cur] = 1;
	c[cur] = col;
	for(auto x : g[cur]) if(x != prev && !c[x]){
		dfs(x, cur, col ^ 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	memset(v, 0, sizeof(v));
	memset(c, 0, sizeof(c));
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(i, n) if(!v[i]){
		dfs(i, -1, 0);
	}
	int f = 0;
	rep(i, n){
		for(int u : g[i]){
			if(c[i] == c[u]) f = 1;
		}
	}
	if(f) cout << -1 << endl;
	else{
		int ans1 = 0, ans2 = 0;
		vi ret1, ret2;
		rep(i, n){
			if(c[i]) ans1++, ret1.pb(i + 1);	
			else ans2++, ret2.pb(i + 1);
		}
		cout << ans1 << endl;
		rep(i, ret1.size()) cout << ret1[i] << " ";
		cout << endl;
		cout << ans2 << endl;
		rep(i, ret2.size()) cout << ret2[i] << " ";
		cout << endl;

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
