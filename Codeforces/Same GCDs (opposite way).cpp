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

vector<ll> primeDiv;

ll g;

ll f(ll div, ll b){
	return (ll)((b / (div * g)));
}


ll solve(int bs, ll low, ll up){
	ll tmp = 1;
	int cnt = 0;
	rep(i, primeDiv.size()) if((1 << i) & bs) tmp *= primeDiv[i], cnt++;
	ll ret = (ll)(f(tmp, up) - f(tmp, low));
	if(cnt % 2 == 1) ret = -ret;
	return ret;
}

void solve(){
	ll a, m;
	cin >> a >> m;
	g = gcd(a, m);
	ll ans = 0;
	ll low = a - 1, up = a + m - 1;
	ll x = m / g;
	for(ll i = 2; (i * i) <= x; i++){
		if(x % i == 0) primeDiv.pb(i);
		while(x % i == 0) x /= i;
	}
	if(x > 1) primeDiv.pb(x);
	int n = (int)primeDiv.size();
	rep(i, (1 << n)){
		ans += solve(i, low, up);
	}
	cout << ans << endl;
	primeDiv.clear();
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

