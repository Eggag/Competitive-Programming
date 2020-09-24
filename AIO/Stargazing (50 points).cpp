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
const int MAXN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n = 1e6 + 5;
int b[MAXN], s1[4 * MAXN];

void build(int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		s1[id] = b[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s1[id] = min(s1[id * 2], s1[id * 2 + 1]);
}

int minQ(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return 1e9;
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return min(minQ(x, y, id * 2, l, mid), minQ(x, y, id * 2 + 1, mid, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n1;
	cin >> n1;
	vector<pi> p(n1);
	map<int, vi> m;
	rep(i, n1) cin >> p[i].fi >> p[i].se, m[p[i].se].pb(p[i].fi);
	rep(i, MAXN) b[i] = 1e9;
	rep(i, n1) b[p[i].fi] = min(b[p[i].fi], p[i].se);
	build();
	int ans = 0;
	for(pair<int, vi> x : m){
		vi y = x.se;
		sort(all(y));
		if(x.se.size() > 1 && y[(int)y.size() - 1] - y[0] >= 2){
			int mn = minQ(y[0] + 1, y[(int)y.size() - 1]);
			if(mn < x.fi) ans = max(ans, abs(mn - x.fi) + (y[(int)y.size() - 1] - y[0]));
		}
	}
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
