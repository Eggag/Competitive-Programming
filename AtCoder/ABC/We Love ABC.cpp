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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll mypow(ll a, ll p){
	if(p <= 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1) % MOD)) % MOD;
	ll x = mypow(a, p / 2) % MOD;
	return (x * x) % MOD;
}

ll inv(ll base){
	return mypow(base, MOD - 2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	int q = 0;
	rep(i, n) if(s[i] == '?') q++;
	ll ans = 0;
	ll ar = 0, br = 0;
	rep(i, n){
		if(s[i] == 'A') (ar += mypow(3, q)) %= MOD;
		if(s[i] == 'B') (br += ar) %= MOD;
		if(s[i] == 'C') (ans += br) %= MOD;
		if(s[i] == '?'){
			(ans += br * inv(3)) %= MOD; //in a third of cases
			(br += ar * inv(3)) %= MOD; //in a third it is a B
			(ar += mypow(3, q - 1)) %= MOD; //in a third it is an
		}
		//debug(ans);
		//debug(ar);
		//debug(br);
		//cout << "-----" << endl;
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
