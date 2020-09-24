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
	ll l, r;
	cin >> l >> r;
	if(l == r){
		cout << (l % 9 == 0 ? 9 : l % 9) << endl;
		return;
	}
	if((r - l) < 1001){
		ll ans1 = 0;
		while(true){
			ans1 += (l % 9 == 0 ? 9 : l % 9);
			if(l == r) break;
			l++;
		}
		cout << ans1 << endl;
		return;
	}
	ll ans = 0;
	while(l % 9 != 1){
		ans += (l % 9 == 0 ? 9 : l % 9);
		l++;
	}
	ll div = (r - l + 1) / 9;
	ans += (ll)(1LL * div * 45);
	l += (ll)(div * (ll)9);
	if(l <= r){
		while(true){
			ans += (l % 9 == 0 ? 9 : l % 9);
			if(l == r) break;
			l++;
		}
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
