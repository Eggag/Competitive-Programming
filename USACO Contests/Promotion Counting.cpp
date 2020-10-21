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

int n;
vi g[mxN];
int p[mxN], p1[mxN], t[mxN];
vi s[4 * mxN];
int num = 0;
int st[mxN], en[mxN];

vi merge(vi a, vi b){
	int x = 0, y = 0;
	int m = a.size(), k = b.size();
	vi c;
	while(x < m || y < k){
		if(y == k) c.pb(a[x]), x++;
		else if(x == m) c.pb(b[y]), y++;
		else{
			if(a[x] < b[y]) c.pb(a[x]), x++;
			else c.pb(b[y]), y++;
		}
	}
	//assert((int)c.size() == ((int)b.size() + (int)a.size()));
	//assert(is_sorted(all(c)));
	return c;
}

void build(int id = 1, int l = 0, int r = num){
	if(l == r){
		s[id] = {t[l]};
		return;
	}
	int m = (l + r) / 2;
	build(id << 1, l, m);
	build(id << 1 | 1, m + 1, r);
	s[id] = merge(s[id << 1], s[id << 1 | 1]);
}

int query(int id, int l, int r, int x, int y, int q){
	if(l > y || r < x) return 0;
	if(x <= l && y >= r){
		//we binary search for the number above the query
		int num = (s[id].end() - ub(all(s[id]), q));
		return num;
	}
	int m = (l + r) / 2;
	return query(id << 1, l, m, x, y, q) + query(id << 1 | 1, m + 1, r, x, y, q);
}

void dfs(int cur, int prev){
	st[cur] = num++;
	for(int x : g[cur]) if(x != prev) dfs(x, cur);
	en[cur] = num++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
	cin >> n;
	rep(i, n) cin >> p[i];
	repn(i, 1, n){
		int x;
		cin >> x;
		x--;
		g[i].pb(x);
		g[x].pb(i);
	}
	dfs(0, -1);
	rep(i, n) t[st[i]] = p[i];
	build();
	rep(i, n){
		int ans = query(1, 0, num, st[i], en[i], p[i]);
		cout << ans << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
