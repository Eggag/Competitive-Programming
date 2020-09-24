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
#define ar array
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int m, n, k, t;
ar<int, 3> p1[mxN];
int a[mxN];

bool cmp(ar<int, 3> f, ar<int, 3> g){
	return f[0] < g[0];
}

bool check(int g){
	int mn = 1e9;
	rep(i, m) if(a[i] >= g) mn = min(mn, a[i]);
	int tot = n + 1, nm = 0;
	vi cnt(mxN, 0);
	rep(i, k) if(mn < p1[i][2]){
		cnt[p1[i][0]]++;
		cnt[p1[i][1] + 1]--;
	}
	partial_sum(all(cnt), cnt.begin());
	rep(i, mxN) if(cnt[i]) nm++;
	tot += 2 * nm;
	return tot <= t;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> m >> n >> k >> t;
	int mn = 1e9, mx = 0;
	rep(i, m) cin >> a[i], mn = min(a[i], mn), mx = max(mx, a[i]);
	rep(i, k){
		int c, d, e;
		cin >> c >> d >> e;
		p1[i] = {c, d, e};
	}
	sort(p1, p1 + k, cmp);
	int l = mn, r = mx + 1;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	int ans = 0;
	rep(i, m) if(a[i] >= l) ans++;
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
