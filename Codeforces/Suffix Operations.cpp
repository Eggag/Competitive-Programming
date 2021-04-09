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
	vector<pair<int, ll>> b;
	rep(i, n) cin >> a[i];
	int cnt = 1;
	repn(i, 1, n){
		if(a[i] == a[i - 1]) cnt++;
		else{
			b.pb(mp(cnt, a[i - 1]));
			cnt = 1;
		}
	}
	b.pb(mp(cnt, a[n - 1]));
	int m = b.size();
	if(m == 1){
		cout << 0 << endl;
		return;
	}
	ll bst = -1e18;
	int ind = -1;
	repn(i, 1, m - 1) if(b[i].fi == 1){
		ll cr = abs(b[i + 1].se - b[i].se) + abs(b[i].se - b[i - 1].se);
		ll nxt = abs(b[i + 1].se - b[i - 1].se);
		if((cr - nxt) > bst){
			bst = cr - nxt;
			ind = i;
		}
	}
	if(abs(b[0].se - b[1].se) > bst && b[0].fi == 1){
		bst = abs(b[0].se - b[1].se);
		ind = 0;
	}
	if(abs(b[m - 1].se - b[m - 2].se) > bst && b[m - 1].fi == 1){
		bst = abs(b[m - 1].se - b[m - 2].se);
		ind = m - 1;
	}
	if(bst > 0) b.erase(b.begin() + ind);
	int p = (int)b.size() - 1;
	ll ans = 0LL;
	while(p >= 0){
		ll cur = b[p].se;
		p--;
		if(p == -1) break;
		ans += abs(cur - b[p].se);
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
