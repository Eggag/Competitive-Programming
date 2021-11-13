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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int cnt[mxN];

void solve(){
	int n, m;
	cin >> n >> m;
	vi a(n);
	rep(i, m) cnt[i] = 0;
	rep(i, n) cin >> a[i], cnt[a[i] % m]++;
	int ans = (cnt[0] ? 1 : 0);
	repn(i, 1, m){
		int rm = m - i;
		if(rm < i) continue;
		int mn = min(cnt[i], cnt[rm]);
		if(max(cnt[i], cnt[rm]) > mn) mn = 2 * mn + 1;
		else mn = 2 * mn;
		if(cnt[i] || cnt[rm]) ans += (cnt[i] + cnt[rm]) - mn + 1;
	}
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
