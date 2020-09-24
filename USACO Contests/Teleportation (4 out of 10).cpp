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
	freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	ll tot = 0;
	ll mn = 1e9, mx = -1e9;
	rep(i, n){
		cin >> a[i] >> b[i];
		tot += abs(a[i] - b[i]);
		mn = min({mn, a[i], b[i]});
		mx = max({mx, a[i], b[i]});
	}
	ll ans = 1e18;
	rep(k, n){
		ll i = b[k];
		ll cur = tot;
		rep(j, n){
			cur -= max(0LL, abs(a[j] - b[j]) - (abs(a[j]) + abs(b[j] - i)));
		}
		ans = min(ans, cur);
	}	
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
