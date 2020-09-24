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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n, k;
	cin >> n >> k;
	vi x(n), y(n);
	int mn1 = 1e9, mx1 = 0;
	rep(i, n) cin >> x[i], mn1 = min(mn1, x[i]), mx1 = max(mx1, x[i]);
	rep(i, n) cin >> y[i];
	if((2 * k) >= mx1 - mn1){
		cout << n << endl;
		return;
	}
	sort(all(x));
	vi mx(n, 0), nm(n, 0);
	for(int i = n - 1; i >= 0; i--){
		if(i != n - 1) mx[i] = mx[i + 1];
		int l = i, r = n - 1;
		while(l < r){
			int mid = (l + r + 1) / 2;
			if(x[mid] <= (x[i] + k)) l = mid;
			else r = mid - 1;
		}
		l = min(l, n - 1);
		nm[i] = l + 1;
		mx[i] = max(mx[i], l - i + 1);
	}
	int ans = 0;
	rep(i, n){
		if((x[n - 1] - x[i]) <= 2 * k) ans = max(ans, n - i);
		int cur = nm[i] - i;
		if(nm[i] < n) cur += mx[nm[i]];
		ans = max(ans, cur);
	}
	cout << ans << endl;
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
