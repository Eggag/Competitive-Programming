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
#define ar array

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m), b(m);
	vi vis(m, 0);
	vector<ar<ll, 3>> p;
	rep(i, m){
		cin >> a[i] >> b[i];
		p.pb(ar<ll, 3>{a[i], 0, i});
		p.pb(ar<ll, 3>{b[i], 1, i});
	}
	sort(all(p));
	reverse(all(p));
	ll ans = 0LL, cur = 0LL, cnt = 0LL;
	rep(i, p.size()){
		if(!p[i][1]) vis[p[i][2]] = 1, cur += p[i][0], cnt++;
		else{
			if(vis[p[i][2]]) ans = max(ans, cur + (n - cnt) * p[i][0]);
			else ans = max(ans, cur + a[p[i][2]] + (n - cnt - 1) * p[i][0]);
		}
		if(cnt >= n){
			ans = max(ans, cur);
			break;
		}
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
