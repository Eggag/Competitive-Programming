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

vector<pi> g[50005];
ll d[50005]; //the max in that subtree
ll mx = 0, ans = 0; //max size

ll dfs0(int cur, int prev, ll sum){
	int ret = 0;
	int f = 0;
	for(pi x : g[cur]) if(x.fi != prev){
		int nw = dfs0(x.fi, cur, sum + x.se);
		ret = max(ret, nw);
		f = 1;
	}
	if(!f) return d[cur] = sum;
	d[cur] = ret;
	mx = max(mx, d[cur]);
	return d[cur];
}

void dfs1(int cur, int prev, ll add){
	ans += max((mx - d[cur]) - add, 0LL);
	add += max((mx - d[cur]) - add, 0LL);
	for(pi x : g[cur]) if(x.fi != prev) dfs1(x.fi, cur, add);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("sculpin.txt", "r", stdin);
	freopen("sculpout.txt", "w", stdout);
	int n;
	cin >> n;
	rep(i, n){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if((a + b + c + d) == 0) continue;
		g[i].pb(mp(a - 1, b));
		g[a - 1].pb(mp(i, b));
		g[i].pb(mp(c - 1, d));
		g[c - 1].pb(mp(i, d));
	}
	dfs0(0, -1, 0LL);
	dfs1(0, -1, 0LL);
	/*
	rep(i, n){
		cout << "Max leaf dist of " << i + 1 << " is " << d[i] << endl;
	}
	*/
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
