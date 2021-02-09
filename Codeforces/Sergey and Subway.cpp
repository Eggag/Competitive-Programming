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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n;
vi g[mxN];
ll cnt[2][mxN];
ll d[2][mxN];
ll ans = 0LL, ans2 = 0LL;

void dfs0(int cur, int prev, int de = 0){
	cnt[de & 1][cur] = 1;
	for(int x : g[cur]) if(x != prev){
		dfs0(x, cur, 1 - de);
		cnt[0][cur] += cnt[0][x];
		cnt[1][cur] += cnt[1][x];
	}
	d[0][cur] += (cnt[0][cur] - (de % 2 == 0));
	d[1][cur] += (cnt[1][cur] - (de & 1));
	for(int x : g[cur]) if(x != prev){
		d[0][cur] += d[0][x];
		d[1][cur] += d[1][x];
	}
}

void dfs(int cur, int prev, int de = 0, ll even = 0LL, ll odd = 0LL, ll evc = 0LL, ll odc = 0LL){
	if(de & 1){
		ans += (d[1][cur] / 2) + ((d[0][cur] - cnt[0][cur]) / 2) + cnt[0][cur];
		ans2 += (odd / 2) + ((even - evc) / 2) + evc;
	}
	else{
		ans += (d[0][cur] / 2) + ((d[1][cur] - cnt[1][cur]) / 2) + cnt[1][cur];
		ans2 += (even / 2) + ((odd - odc) / 2) + odc;
	}
	ll nev = even, nod = odd;
	for(int x : g[cur]) if(x != prev){
		evc += cnt[0][x], odc += cnt[1][x];
		nev += d[0][x] + cnt[0][x], nod += d[1][x] + cnt[1][x];
	}
	for(int x : g[cur]) if(x != prev){
		nev -= d[0][x] + cnt[0][x], nod -= d[1][x] + cnt[1][x];
		evc -= cnt[0][x], odc -= cnt[1][x];
		nev += evc, nod += odc;
		dfs(x, cur, 1 - de, nev, nod, evc, odc);	
		nev -= evc, nod -= odc;
		nev += d[0][x] + cnt[0][x], nod += d[1][x] + cnt[1][x];
		evc += cnt[0][x], odc += cnt[1][x];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n - 1){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs0(0, -1);
	dfs(0, -1);
	cout << ans + (ans2 / 2) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
