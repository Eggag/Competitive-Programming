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
const int mxN = 305;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
string s[mxN];

ll mypow(ll a, ll p){
	if(p == 0) return 1;
	if(p & 1) return (a * mypow(a, p - 1)) % MOD;
	ll x = mypow(a, p / 2);
	return sq(x) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	rep(i, m){
		if(s[0][i] == 'S') s[0][i] = 'N';
		else s[0][i] = 'S';
		int cnt = 1;
		ll ans = 1LL;
		repn(j, 1, m){
			if(s[0][j] == s[0][j - 1]) cnt++;
			else{
				(ans *= mypow(2, cnt - 1)) %= MOD;
				cnt = 1;
			}
		}
		(ans *= mypow(2, cnt - 1)) %= MOD;
		cout << ans << " \n"[i == (m - 1)];
		if(s[0][i] == 'S') s[0][i] = 'N';
		else s[0][i] = 'S';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
