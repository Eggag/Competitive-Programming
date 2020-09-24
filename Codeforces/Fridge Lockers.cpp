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
	int n, m;
	cin >> n >> m;
	vi a(n);
	vector<pi> b(n);
	rep(i, n) cin >> a[i], b[i] = mp(a[i], i);
	if(n == 2){
		cout << -1 << endl;
		return;
	}
	if(m < n){
		cout << -1 << endl;
		return;
	}
	sort(all(b));
	vector<pi> ans;
	int ret = 0;
	rep(i, n){
		ans.pb(mp(i, (i + 1) % n));
		m--;
		ret += a[i] + a[(i + 1) % n];
	}
	while(m--){
		ans.pb(mp(b[0].se, b[1].se));		
		ret += b[0].fi + b[1].fi;
	}
	cout << ret << endl;
	rep(i, ans.size()){
		cout << ans[i].fi + 1 << " " << ans[i].se + 1 << endl;
	}
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
