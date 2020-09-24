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
	vi a(n);
	rep(i, n) cin >> a[i];
	int mn = 1e9, bst = -1;
	vector<pi> ans(n);
	rep(i, n) ans[i] = {-1, -1};
	rep(i, n){
		if(a[i] > mn){
			ans[i].fi = bst;
		}
		if(a[i] < mn){
			mn = a[i];
			bst = i;
		}
	}
	mn = 1e9;
	for(int i = n - 1; i >= 0; i--){
		if(a[i] > mn){
			ans[i].se = bst;
			if(ans[i].fi != -1){
				cout << "YES" << endl;
				cout << ans[i].fi + 1 << " " << i + 1 << " " << ans[i].se + 1 << endl;
				return;
			}
		}
		if(a[i] < mn){
			mn = a[i];
			bst = i;
		}
	}
	cout << "NO" << endl;
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
