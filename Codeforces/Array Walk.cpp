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

void solve(){
	ll n, k, z;
	cin >> n >> k >> z;
	vector<ll> a(n), sum(n);
	rep(i, n) cin >> a[i];
	ll ans = 0;
	sum[0] = a[0];
	repn(i, 1, n) sum[i] = sum[i - 1] + a[i];
	ans = sum[k - 1];
	rep(i, n - 1){
		if(i >= k) break;
		ll cur1 = 0LL;
		if(i) cur1 = sum[i - 1];
		int lft = k - i;
		rep(j, z + 1){
			if(lft >= (2 * (j) + 1)){
				ll cur = cur1;
				cur += (a[i] + a[i + 1]) * (j + 1);
				int lst = i + 1 + lft - (2 * (j) + 1);
				cur += sum[lst] - sum[i + 1];
				ans = max(ans, cur);
				if(j < z && lst > 1) ans = max(ans, cur - a[lst] + a[lst - 2]);
			}	
		}
	}
	cout << ans << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
