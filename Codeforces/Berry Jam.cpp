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

void solve(){
	int n;
	cin >> n;
	vi a(2 * n);
	map<int, int> mx;
	rep(i, (2 * n)) cin >> a[i];
	rep(i, n + 3) mx[i] = 1e9;
	repn(i, -(n + 3), 0) mx[i] = 1e9;
	vector<pi> cnt(n);
	cnt[0] = mp((a[0] == 1), (a[0] == 2));
	repn(i, 1, n){
		cnt[i].fi = cnt[i - 1].fi + (a[i] == 1);
		cnt[i].se = cnt[i - 1].se + (a[i] == 2);
		assert((i + 1) == (cnt[i].fi + cnt[i].se));
	}
	pi cur = {0, 0};
	mx[0] = 0;
	for(int i = (2 * n) - 1; i >= n; i--){
		if(a[i] == 1) cur.fi++;
		if(a[i] == 2) cur.se++;
		mx[cur.fi - cur.se] = ((2 * n) - i);
	}
	int best = (2 * n);
	rep(i, n){
		int diff = (cnt[i].fi - cnt[i].se);
		int nw = -diff;
		if(mx[nw] != 1e9) best = min(best, ((n - (i + 1)) + (n - mx[nw])));
	}
	best = min(best, n + (n - mx[0]));
	cout << best << endl;
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
