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
 
int n, s, q, e;
int sh[100005];
int a[100005], b[100005];
ll w[100005];
vector<pair<int, ll>> g[100005];
 
int st[100005], en[100005];
int timer = 0;
 
void dfs(int cur, int prev){
	st[cur] = timer++;
	for(pair<int, ll> x : g[cur]) if(prev != x.fi) dfs(x.fi, cur);
	en[cur] = timer++;
}
 
int intersect(int l, int r, int l1, int r1){
	return (l >= l1 && r <= r1);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> s >> q >> e;
	e--;
	rep(i, n - 1){
		cin >> a[i] >> b[i] >> w[i];
		a[i]--, b[i]--;
		g[a[i]].pb(mp(b[i], w[i]));
		g[b[i]].pb(mp(a[i], w[i]));
	}
	rep(i, s) cin >> sh[i], sh[i]--;
	dfs(e, -1);
	rep(i, q){
		int t, r;
		cin >> t >> r;
		t--, r--;
		int cnt = 0;
		int l = a[t];
		if(st[a[t]] < st[b[t]]) l = b[t];
		cnt += intersect(st[r], en[r], st[l], en[l]);
		if(cnt != 1) cout << "escaped" << endl;
		else cout << 0 << endl;
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