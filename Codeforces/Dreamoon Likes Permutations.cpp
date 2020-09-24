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

int MAXN;

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(MAXN, 0);
	}
	void add(int ind, T delta){
		for(; ind < MAXN; ind = ind | (ind + 1)){
			bit[ind] += delta;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ind >= 0; ind = (ind & (ind + 1)) - 1){
			sum += bit[ind];
		}
		return sum;
	}
};

void solve(){
	int n;
	cin >> n;
	MAXN = n + 5;
	vi a(n);
	rep(i, n) cin >> a[i];
	BIT<int> bit, bit1;
	unordered_map<int, int> vis, vis1;
	vector<pi> ans;
	vi pos(n, 0);
	int mx = 0, mx1 = 0;
	rep(i, n){
		if(vis[a[i]]) break;
		vis[a[i]] = 1;
		mx = max(mx, a[i]);
		bit.add(a[i], 1);
		if(bit.query(mx) == mx) pos[i] = 1;
	}
	for(int i = n - 1; i >= 1; i--){
		if(vis1[a[i]]) break;
		vis1[a[i]] = 1;
		mx1 = max(mx1, a[i]);
		bit1.add(a[i], 1);
		if(bit1.query(mx1) == mx1 && pos[i - 1]){
			ans.pb({i, n - i});
		}
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i].fi << " " << ans[i].se << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
