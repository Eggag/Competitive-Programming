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

struct seg{
	ll t[1 << 19];
	int sz;
	seg(int s){
		sz = s;
		rep(i, 1 << 19) t[i] = 1e18;
	}
	void update(int id, int l, int r, int p, ll val){
		if(l == r){
			t[id] = min(t[id], val);
			return;
		}
		int m = (l + r) / 2;
		if(p <= m) update(id << 1, l, m, p, val);
		else update(id << 1 | 1, m + 1, r, p, val);
		t[id] = min(t[id << 1], t[id << 1 | 1]);
	}
	void update(int p, ll val){
		update(1, 0, sz, p, val);
	}
	ll query(int id, int l, int r, int x, int y){
		if(x <= l && y >= r) return t[id];
		if(r < x || l > y) return 1e18;
		int m = (l + r) / 2;
		return min(query(id << 1, l, m, x, y), query(id << 1 | 1, m + 1, r, x, y));
	}
	ll query(int x, int y){
		return query(1, 0, sz, x, y);
	}
};

ll dp[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	seg tree(n);
	rep(i, mxN) dp[i] = 1e18;
	dp[0] = 1;
	tree.update(0, 1);
	if(s[0] == '1'){
		dp[min(n - 1, k)] = 1;
		tree.update(min(n - 1, k), 1);
	}
	repn(i, 1, n){
		if(s[i] == '1'){
			dp[min(n - 1, i + k)] = min(dp[min(n - 1, i + k)], ((i - k - 1) < 0 ? 0 : tree.query(max(0, i - k - 1), n - 1)) + i + 1);
			tree.update(min(n - 1, i + k), dp[min(n - 1, i + k)]);
		}
		dp[i] = min(dp[i], dp[i - 1] + i + 1);
		tree.update(i, dp[i]);
	}
	cout << dp[n - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
