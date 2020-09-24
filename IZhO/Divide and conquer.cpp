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
	int n;
	cin >> n;
	vector<ll> x(n), g(n), d(n);
	rep(i, n) cin >> x[i] >> g[i] >> d[i];
	vector<ll> pref(n, 0LL);
	pref[0] = d[0];
	ll tot = 0LL;
	ll D = d[0];
	repn(i, 1, n){
		tot += x[i] - x[i - 1];
		D += d[i];
		pref[i] = D - tot;
	}
	vector<ll> gold(n, 0LL);
	gold[0] = g[0];
	repn(i, 1, n) gold[i] = gold[i - 1] + g[i];
	vector<ll> mx(n, -1e9);
	mx[n - 1] = pref[n - 1];
	for(int i = n - 2; i >= 0; i--) mx[i] = max(mx[i + 1], pref[i]);
	ll ans = 0LL;
	rep(i, n){
		int l = i, r = n - 1;
		while(l < r){
			int mid = (l + r + 1) / 2;
			if(mx[mid] >= (pref[i] - d[i])) l = mid;
			else r = mid - 1;
		}
		ans = max(ans, gold[l] - (i ? gold[i - 1] : 0LL));
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
