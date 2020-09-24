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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	vector<ll> x(n), y(m);
	rep(i, n) cin >> x[i];
	rep(i, m) cin >> y[i];
	ll one = 0, two = 0, cnt = 0, prev = 0;
	repn(i, 1, n){
		cnt++;
		ll cur = ((1LL * cnt * (((ll)(x[i] - x[i - 1]) + MOD)) % MOD) + MOD) % MOD;
		one = (one + prev + MOD) % MOD;
		one = (one + cur + MOD) % MOD;
		prev = cur + prev;		
	}
	cnt = 0, prev = 0;
	repn(i, 1, m){
		cnt++;
		ll cur = ((1LL * cnt * (((ll)(y[i] - y[i - 1]) + MOD)) % MOD) + MOD) % MOD;
		two = (two + prev + MOD) % MOD;
		two = (two + cur + MOD) % MOD;
		prev = cur + prev;		
	}
	ll ans = ((one * two) + MOD) % MOD;
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
