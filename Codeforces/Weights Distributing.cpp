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
#define inf 0x3f3f3f3f
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
int a[3];
vi g[mxN];
ll sum[mxN];
int sh[3][mxN];

ll f(int a, int b, int c){
	rep(i, n) rep(j, 3) sh[j][i] = inf;
	sh[0][a] = 0, sh[1][b] = 0, sh[2][c] = 0;
	queue<int> q;
	q.push(a);
	while(!q.empty()){
		int cr = q.front();
		q.pop();
		for(int x : g[cr]) if(sh[0][x] == inf){
			sh[0][x] = sh[0][cr] + 1;
			q.push(x);
		}
	}
	q.push(b);
	while(!q.empty()){
		int cr = q.front();
		q.pop();
		for(int x : g[cr]) if(sh[1][x] == inf){
			sh[1][x] = sh[1][cr] + 1;
			q.push(x);
		}
	}
	q.push(c);
	while(!q.empty()){
		int cr = q.front();
		q.pop();
		for(int x : g[cr]) if(sh[2][x] == inf){
			sh[2][x] = sh[2][cr] + 1;
			q.push(x);
		}
	}
	ll mn = 1e18;
	rep(i, n){
		int ind = sh[1][i] - 1;
		ll cr = ((~ind ? sum[ind] : 0) * 2LL);
		int ind1 = ind + sh[2][i] + sh[0][i];
		if(ind1 >= m) continue;
		cr += (~ind1 ? sum[ind1] : 0) - (~ind ? sum[ind] : 0);
		mn = min(mn, cr);
	}
	return mn;
}

void solve(){
	cin >> n >> m >> a[0] >> a[1] >> a[2];
	a[0]--, a[1]--, a[2]--;
	vector<ll> p(m);
	rep(i, m) cin >> p[i];
	sort(all(p));
	sum[0] = p[0];
	repn(i, 1, m) sum[i] = sum[i - 1] + p[i];
	rep(i, n) g[i].clear();
	rep(i, m){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	if(a[0] == a[1] && a[1] == a[2]) cout << 0 << '\n';
	else cout << f(a[0], a[1], a[2]) << '\n';
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
