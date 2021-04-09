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
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	vector<ll> b;
	ll cur = 1LL;
	repn(i, 1, n){
		if(a[i] == a[i - 1]) cur++;
		else b.pb(cur), cur = 1LL;
	}
	b.pb(cur);
	sort(all(b));
	int m = b.size();
	vector<ll> sum(m);
	sum[0] = b[0];
	repn(i, 1, m) sum[i] = sum[i - 1] + b[i];
	ll ans = 0LL;
	repn(i, 1, b[m - 1] + 1){
		auto it = lb(all(b), i);
		ans = max(ans, (ll)(1LL * (m - (it - b.begin())) * i));
	}
	cout << n - ans << '\n';
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
