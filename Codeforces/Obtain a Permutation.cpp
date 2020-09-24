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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<vi> a(n, vi(m, 0));
	rep(i, n) rep(j, m) cin >> a[i][j];
	ll ans = 0LL;
	vi num(n, 0);
	rep(j, m){
		rep(i, n) num[i] = 0;
		rep(i, n){
			if(a[i][j] % m == ((j + 1) % m) && a[i][j] <= ((n - 1) * m) + (j + 1)){
				int k = max(0, a[i][j] - 1) / m;
				if(i >= k) num[(i - k)]++;
				else num[(i + (n - k))]++;
			}
		}
		ll cur = 1e18;
		rep(i, n) cur = min(cur, (ll)(i + (n - num[i])));
		ans += cur;
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
