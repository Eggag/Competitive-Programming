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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	if(n % 3 == 0 || m % 3 == 0){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1e18;
	for(ll i = max(1LL, n / 2); i <= min(n - 1, ((n + 1) / 2)); i++){
		for(ll j = 1; j < m; j++){
			ll a = 1LL * i * j;
			ll b = 1LL * (n - i) * j;
			ll c = 1LL * (m - j) * n;
			ans = min(ans, max({abs(a - b), abs(a - c), abs(b - c)}));
		}
	}
	swap(n, m);
	for(ll i = max(1LL, n / 2); i <= min(n - 1, ((n + 1) / 2)); i++){
		for(ll j = 1; j < m; j++){
			ll a = 1LL * i * j;
			ll b = 1LL * (n - i) * j;
			ll c = 1LL * (m - j) * n;
			ans = min(ans, max({(ll)abs(a - b), (ll)abs(a - c), (ll)abs(b - c)}));
		}
	}
	ans = min(ans, min(m, n));
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
