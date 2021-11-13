#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
vi g[mxN];
int f[mxN], p[mxN];
int st[mxN], en[mxN];
ll a[mxN], s[4 * mxN], lazy[4 * mxN];
int nm = 0;

void down(int id, int l, int r){
	if(lazy[id]){
		s[id] += 1LL * lazy[id] * (r - l);
		if((r - l) > 1){
			lazy[id << 1] += lazy[id];
			lazy[(id << 1) + 1] += lazy[id];
		}
	}
	lazy[id] = 0;
}
 
void increase(int x, int y, ll u, int id = 1, int l = 0, int r = n + 1){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] += u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id << 1, l, mid);
	increase(x, y, u, (id << 1) + 1, mid, r);
	s[id] = s[id << 1] + s[(id << 1) + 1];
}
 
ll sum(int x, int y, int id = 1, int l = 0, int r = n + 1){
	down(id, l, r);
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}

void dfs0(int cur, int prev){
	p[cur] = prev;
	st[cur] = nm++;
	for(int x : g[cur]) if(x != prev) dfs0(x, cur);
	en[cur] = nm;
}

void dfs(int cur, int prev, int t){
	int bd = 1;
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur, t);
		if(!f[x]) bd = 0;
	}
	f[cur] = (bd && cur < t);
}

void dfs1(int cur, int prev, int cnt = 0){
	if(f[cur]) cnt++;
	a[cur] = cnt;
	for(int x : g[cur]) if(x != prev) dfs1(x, cur, cnt);
}

int check(int g){
	memset(f, 0, sizeof(f));
	dfs(n - 1, -1, g);
	int cnt = 0;
	rep(i, n) cnt += f[i];
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs0(n - 1, -1);
	int l = 1, r = n;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid) >= k) r = mid;
		else l = mid + 1;
	}
	int ans = check(l);
	dfs1(n - 1, -1);
	for(int i = l - 1; i >= 0; i--) if(f[i]){
		int owo = a[i] + sum(st[i], st[i] + 1);
		if(ans - owo >= k){
			ans -= owo;
			int cr = i;
			while(cr != -1 && f[cr]){
				f[cr] = 0;
				increase(st[cr], en[cr], -1);
				cr = p[cr];
			}
		}
	}
	assert(ans == k);
	vi res;
	rep(i, n) if(f[i]) res.pb(i + 1);
	assert((int)(res.size()) == k);
	for(int x : res) cout << x << ' ';
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/

