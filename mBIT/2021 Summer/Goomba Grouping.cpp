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
	int n;
	ll k;
	cin >> n >> k;
	if(n < 5){
		cout << -1 << '\n';
		return;
	}
	vector<ll> ans;
	if(!k){
		if(n & 1){
			ans = {5, 5, 7, 7, 10};
			while((int)(ans.size()) < n) ans.pb(5);
		}
		else{
			ans = {3, 3, 3, 7, 7, 9};
			while((int)(ans.size()) < n) ans.pb(3);
		}
	}
	else{
		if(n & 1){
			ans = {5 * k, 5 * k, 7 * k, 7 * k, 11 * k};
			while((int)(ans.size()) < n) ans.pb(5 * k);
		}
		else{
			ans = {5 * k, 5 * k, 5 * k, 7 * k, 7 * k, 16 * k};
			while((int)(ans.size()) < n) ans.pb(5 * k);
		}
	}
	rep(i, n) cout << ans[i] << " ";
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
