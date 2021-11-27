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
	int n, a, b;
	cin >> n >> a >> b;
	vi vis(n + 1, 0), cr, cr1;
	vis[b] = 1;
	cr.pb(b);
	rep(i, a - 1) if(!vis[i + 1]){
		cr.pb(i + 1), vis[i + 1] = 1;
	}
	if(cr.size() > (n / 2)){
		cout << -1 << '\n';
		return;
	}
	for(int i = b - 1; i >= 1; i--){
		if(cr.size() == (n / 2)) break;
		if(!vis[i]){
			cr.pb(i);
			vis[i] = 1;
		}
	}
	if(cr.size() < (n / 2)){
		cout << -1 << '\n';
		return;
	}
	if(vis[a]){
		cout << -1 << '\n';
		return;
	}
	for(int i = n; i >= 1; i--) if(!vis[i]) cr1.pb(i);
	int mx = 0, mn = 1e9;
	rep(i, n / 2) mx = max(mx, cr[i]);
	rep(i, n / 2) mn = min(mn, cr1[i]);
	if(mx != b || mn != a){
		cout << -1 << '\n';
		return;
	}
	rep(i, n / 2) cout << cr1[i] << ' ';
	rep(i, n / 2) cout << cr[i] << ' ';
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
