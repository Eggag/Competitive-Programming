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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int k, n, m;
	cin >> k >> n >> m;
	vi a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	int x = 0, y = 0;
	vi ans;
	while(x < n || y < m){
		int f = 0;
		if(x < n){
			if(a[x] <= k){
				ans.pb(a[x]), f = 1, x++;
				if(!a[x - 1]) k++;
			}
		}
		if(y < m && !f){
			if(b[y] <= k){
				ans.pb(b[y]), f = 1, y++;
				if(!b[y - 1]) k++;
			}
		}
		if(!f){
			cout << -1 << '\n';
			return;
		}
	}
	rep(i, ans.size()) cout << ans[i] << " ";
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
