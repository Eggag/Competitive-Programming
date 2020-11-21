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
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans = 0LL;
	vector<ll> nm(n);
	ll cnt0 = 0LL, cnt1 = 0LL;
	rep(i, n){
		nm[i] = __builtin_popcountll(a[i]);
		if(i) nm[i] += nm[i - 1];
		int tot = 0, mx = 0;
		for(int j = i; j >= max(0, i - 62); j--){
			int cur = __builtin_popcountll(a[j]);
			mx = max(cur, mx);
			tot += cur;
			if(mx <= (tot / 2) && tot % 2 == 0) ans++;
		}
		if(i >= 64){
			if(nm[i - 64] & 1) cnt1++;
			else cnt0++;
		}
		if(i == 63) cnt0++;
		if(nm[i] & 1) ans += cnt1;
		else ans += cnt0;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
