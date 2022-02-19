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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];
int cnt[mxN], cnt1[mxN];

struct seg{
	ll dat[1 << 19];
	int sz;
	seg(int s){
		sz = s;
		for(int i = 0; i < (1 << 19); i++){
			dat[i] = 1e18;
		}
	}
	void update(int i, int s, int e, int x, ll v){
		if(s == e){
			dat[i] = v;
			return;
		}
		int m = (s + e) / 2;
		if(x <= m) update(i << 1, s, m, x, v);
		else update(i << 1 | 1, m + 1, e, x, v);
		dat[i] = max(dat[i << 1], dat[i << 1 | 1]);
	}
	void update(int x, ll v){
		update(1, 0, sz, x, v);
	}
	ll query(int i, int s, int e, int x, int y){
		if(e < x || y < s) return 0;
		if(x <= s && e <= y) return dat[i];
		int m = (s + e) / 2;
		return max(query(i << 1, s, m, x, y), query(i << 1 | 1, m + 1, e, x, y));
	}
	ll query(int x, int y){
		if(y < x) return -1;
		return query(1, 0, sz, x, y);
	}
} tree(mxN);


void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n + 2) g[i].clear(), cnt[i] = 0, cnt1[i] = 0;
	rep(i, n){
		cin >> a[i];
		g[a[i]].pb(i);
		cnt[a[i]]++;
	}
	int mn = 1e9;
	rep(i, n + 2) if(!cnt[i]){
		mn = i;
		break;
	}
	rep(i, n + 1){
		tree.update(i, (g[i].size() ? g[i][0] : 1e18));
	}
	vi ans;
	rep(i, n){
		int uwu = tree.query(0, mn - 1);
		if(uwu == -1) ans.pb(0);
		else{
			ans.pb(mn);
			for(; i <= uwu; i++){
				cnt1[a[i]]++;
				if(cnt1[a[i]] < cnt[a[i]]){
					tree.update(a[i], g[a[i]][cnt1[a[i]]]);
				}
				else mn = min(mn, a[i]);
			}
			i--;
		}
	}
	cout << (int)(ans.size()) << '\n';
	for(int x : ans) cout << x << ' ';
	cout << '\n';
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
