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

ll mypow(ll a, ll p){
	if(p == 0) return 1;
	if(p == 1) return a;
	if(p & 1) return a * mypow(a, p - 1);
	ll x = mypow(a, p / 2);
	return (x * x);
}

void solve(){
	ll p, q;
	cin >> p >> q;
	if(p % q != 0){
		cout << p << endl;
		return;
	}
	ll q1 = q, p1 = p;
	ll ans = 0LL;
	for(ll i = 2LL; (i * i) <= q1; i++){
		if(q1 % i == 0){
			ll cnt = 0LL, cnt1 = 0LL;
			while(q1 % i == 0){
				q1 /= i;
				cnt++;
			}
			while(p1 % i == 0){
				p1 /= i;
				cnt1++;
			}
			ans = max(ans, p / mypow(i, cnt1 - cnt + 1));
		}
	}
	if(q1 > 1){
		ll cnt = 1LL, cnt1 = 0LL;
		while(p1 % q1 == 0){
			p1 /= q1;
			cnt1++;
		}
		ans = max(ans, p / mypow(q1, cnt1 - cnt + 1));
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
