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

ll n, k;

bool check(ll num){
	int cnt = 0;
	int f = 1 - (num & 1);
	ll ans = 0LL;
	while(num <= n){
		ll rm = (1LL << (cnt + f)) - 1;
		rm = min(rm, n - num);
		ans += rm + 1;
		cnt++;
		num *= 2LL;
	}
	return ans >= k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	ll l = 1LL, r = n;
	while(l < r){
		ll mid = (l + r + 1) / 2;
		if(check((2 * mid) - 1)) l = mid;
		else r = mid - 1;
	}
	ll l1 = 1LL, r1 = n;
	while(l1 < r1){
		ll mid1 = (l1 + r1 + 1) / 2;
		if(check(2 * mid1)) l1 = mid1;
		else r1 = mid1 - 1;
	}
	cout << max(check(2 * l1) ? (2 * l1) : 0, check((2 * l) - 1) ? ((2 * l) - 1) : 0) << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
