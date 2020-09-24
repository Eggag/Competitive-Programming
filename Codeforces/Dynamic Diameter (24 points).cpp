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

int n, q, w;
vector<pi> g[100005];
ll lon = 0LL;
int st;

void dfs(int c, int p, ll sum){
	int f = 0;
	for(auto x : g[c]) if(x.fi != p) dfs(x.fi, c, sum + x.se), f = 1;
	if(!f){
		if(sum > lon) st = c, lon = sum;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> q >> w;
	int a[n - 1], b[n - 1], c[n - 1];
	rep(i, n - 1){
		cin >> a[i] >> b[i] >> c[i];
	}
	int last = 0;
	rep(i, q){
		int d, e;
		cin >> d >> e;
		d = (d + last) % (n - 1);
		e = (e + last) % w;
		rep(j, 100005) g[j].clear();
		rep(j, n - 1){
			if(j == d) c[j] = e;
			g[a[j]].pb({b[j], c[j]});
			g[b[j]].pb({a[j], c[j]});
		}
		lon = 0LL;
		st = 1;
		dfs(st, -1, 0LL);
		lon = 0LL;
		dfs(st, -1, 0LL);
		cout << lon << endl;
		last = lon;
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
