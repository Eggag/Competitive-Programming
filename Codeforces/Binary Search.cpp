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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll fact[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, x, pos;
	cin >> n >> x >> pos;
	ll bel = x - 1;
	ll ab = n - bel - 1;
	ll l = 0, r = n;
	ll ans = 1LL;
	fact[0] = 1LL;
	repn(i, 1, 1005) fact[i] = (fact[i - 1] * i) % MOD;
	while(l < r){
		ll mid = (l + r) / 2;
		if(mid < pos){
			(ans *= bel) %= MOD;
			bel--;
			l = mid + 1;
		}
		else if(mid == pos) l = mid + 1;
		else{
			(ans *= ab) %= MOD;
			ab--;
			r = mid;
		}
	}
	(ans *= fact[ab + bel]) %= MOD;
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
