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
	ll k;
	cin >> k;
	if(k == 1){
		cout << "1 1\n";
		return;
	}
	ll nxt = 1;
	for(ll i = 1; (i * i) < k; i++) nxt = i + 1;
	ll nm = 1 + 2 * (nxt - 1);
	ll pr = sq(nxt - 1);
	if((k - pr) <= (nm + 1) / 2){
		cout << k - pr << ' ' << nxt << '\n';
	}
	else{
		ll rem = (k - pr) - ((nm + 1) / 2);
		cout << (nm + 1) / 2 << ' ' << nxt - rem << '\n';
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
