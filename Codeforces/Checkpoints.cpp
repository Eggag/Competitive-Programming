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
	ll k;
	cin >> k;
	if(k & 1){
		cout << -1 << endl;
		return;
	}
	vi ans;
	ans.pb(1);
	while(k){
		int cnt = 1;
		while(((1LL << (cnt + 1)) - 2) <= k) cnt++;
		rep(i, cnt - 2) ans.pb(0);
		ans.pb(1);
		k -= (1LL << cnt) - 2;
	}
	if(ans.size() > 2000){
		cout << -1 << endl;
		return;
	}
	cout << (int)(ans.size() - 1) << endl;
	rep(i, ans.size() - 1) cout << ans[i] << " ";
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
