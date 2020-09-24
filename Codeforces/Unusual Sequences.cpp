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

ll mypow(ll a, ll p){
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1) % MOD)) % MOD;
	ll x = mypow(a, p / 2) % MOD;
	return (x * x) % MOD;
}

vi pr(int x){
	vi ret;
	for(int i = 2; (i * i) <= x; i++){
		if(x % i == 0){
			ret.pb(i);
			while(x % i == 0) x /= i;
		}
	}
	if(x > 1) ret.pb(x);
	return ret;
}

void solve(int x, int y){
	if(y % x != 0){
		cout << 0 << endl;
		return;
	}
	y /= x;
	int ans = 0;
	vi p = pr(y);
	rep(i, (1 << (int)(p.size()))){
		int cnt = 0, nm = 1;
		rep(j, p.size()) if(i & (1 << j)) cnt++, nm *= p[j];
		int cur = mypow(2, y / nm - 1);
		if(cnt % 2 == 0) (ans += cur) %= MOD;
		else (ans += (MOD - cur)) %= MOD;
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int x, y;
	cin >> x >> y;
	solve(x, y);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
