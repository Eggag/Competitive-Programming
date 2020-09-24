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
	ll n, m, v, p;
	cin >> n >> m >> v >> p;
	vector<ll> a(n + 1);
	repn(i, 1, n + 1) cin >> a[i];
	sort(a.begin() + 1, a.end());
	reverse(a.begin() + 1, a.end());
	//repn(i, 1, n + 1) cout << a[i] << " ";
	//cout << endl;
	vector<ll> sum(n + 1, 0LL);
	sum[0] = 0LL;
	repn(i, 1, n + 1) sum[i] = 1LL * (sum[i - 1] + a[i]);
	ll ans = p;
	for(ll i = p + 1; i <= n; i++){
		if((a[i] + m) < a[p]) continue; //no way
		if((n - i + 1) >= v){
			ans++;
			continue;
		}
		ll num = max(0LL, (v - ((n - i) + 1)));
		num -= (p - 1);
		if(num <= 0){
			ans++;
			continue;
		}
		ll tmp = (ll)((ll)((a[i] + m) * (i - p)) - (ll)(sum[i - 1] - sum[p - 1]));
		if(tmp >= (num * m)) ans++;
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
