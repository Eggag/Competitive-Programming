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
const int logn = 20;
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[mxN], mn[logn][mxN], mx[logn][mxN];
 
int minQ(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return min(mn[t][l], mn[t][r - (1 << t)]);
}

bool check(int g){
	if(g > n) return 0;
	set<int> st;
	int mx = 0;
	rep(i, n - g + 1){
		int cur = minQ(i, i + g);
		st.insert(cur);
		mx = max(mx, cur);
		if(mx > (n - g + 1)) return 0;
		if((int)(st.size()) != (i + 1)) return 0;
	}
	return 1;
}

void solve(){
	cin >> n;
	vi b(n);
	rep(i, n) cin >> a[i], b[i] = a[i];
	sort(all(b));
	string ans = "";
	rep(i, n) ans += '0';
	ans[0] = '1';
	repn(i, 1, b.size()) if(b[i] == b[i - 1]) ans[0] = '0';
	memcpy(mn[0], a, sizeof a);
	for(int l = 0; l < logn - 1; l++){
		for(int i = 0; i + (2 << l) <= n; i++){
			mn[l + 1][i] = min(mn[l][i], mn[l][i + (1 << l)]);
		}
	}
	//now we binary seach
	int l = 2, r = n + 1;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	repn(i, l - 1, n) ans[i] = '1';
	cout << ans << '\n';
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
