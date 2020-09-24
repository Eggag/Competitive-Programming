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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll g[55][55];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j];
	ll ans = 0;
	rep(i, n){
		ll cnt = 0;
		rep(j, m) cnt += g[i][j];
		ans += (1LL << cnt) - 1;
		ans += (1LL << (m - cnt)) - 1;
	}
	rep(j, m){
		ll cnt = 0;
		rep(i, n) cnt += g[i][j];
		ans += (1LL << cnt) - 1;
		ans += (1LL << (n - cnt)) - 1;
	}
	ans -= n * m;
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
