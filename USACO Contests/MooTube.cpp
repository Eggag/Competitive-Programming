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

ll k;
int v;
int cnt;
vector<pair<int, ll>> g[5005];
int vis[5005];

void dfs(int cur, ll mn){
	vis[cur] = 1;
	if(mn != 1e18){
		if(mn >= k) cnt++;
		//debug2(mn, k);
	}
	for(pair<int, ll> u : g[cur]) if(!vis[u.fi]){
		dfs(u.fi, (ll)(min(mn, u.se)));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	rep(i, n - 1){
		int p, q;
		ll r;
		cin >> p >> q >> r;
		p--, q--;
		g[p].pb(mp(q, r));
		g[q].pb(mp(p, r));
	}
	rep(i, q){
		//cout << "New" << endl;
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		cin >> k >> v;
		v--;
		dfs(v, 1e18);
		cout << cnt << endl;
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
