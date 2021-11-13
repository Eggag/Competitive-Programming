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
	ll n, m;
	cin >> n >> m;
	if(m < n){
		cout << 0 << '\n';
		return;
	}
	rep(j, 10) if((n ^ j) > m){
		cout << j << '\n';
		return;
	}
	ll ans = 0LL;
	int lm = 40;
	vi us(50, 0);
	while(true){
		int cr = -1;
		for(int i = lm; i >= 0; i--) if(!(n & (1LL << i))){
			if((n ^ (1LL << i)) <= m){
				cr = i;
				break;
			}
		}
		if(cr == -1) break;
		else ans += (1LL << cr), lm = cr, n ^= (1LL << cr), us[cr] = 1;
	}
	rep(i, 40){
		if(n & (1LL << i)){
			if(!us[i]) ans += (1LL << i);
		}
		else break;
	}
	cout << ans + 1 << '\n';
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
