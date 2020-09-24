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

vector<ll> prime;

ll f(ll b, ll div){
	return (ll)(b / div);
}

ll compute(int b, ll a1, ll b1){
	ll tmp = 1;
	rep(i, prime.size()) if(b & (1 << i)) tmp *= prime[i];
	ll ret = f(b1, tmp) - f(a1 - 1, tmp);
	ll s = 1;
	if(__builtin_popcount(b) % 2 != 0) s = -1;
	return (ret * s);
}

ll solve(){
	ll a, b, n;
	cin >> a >> b >> n;
	ll ans = 0;
	ll n1 = n;
	for(ll i = 2; (i * i) <= n1; i++){
		if(n1 % i == 0) prime.pb(i);
		while(n1 % i == 0) n1 /= i;
	}
	if(n1 > 1) prime.pb(n1);
	int n2 = (int)prime.size();
	rep(i, (1 << n2)) ans += compute(i, a, b);
	prime.clear();
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1) cout << "Case #" << i << ": " << solve() << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
