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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll mypow(ll a, ll p){
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1) % MOD)) % MOD;
	ll x = mypow(a, p / 2) % MOD;
	return (x * x) % MOD;
}

ll cnt[15][mxN], p[mxN];
int v[15];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	ll ans = 0LL;
	p[0] = 1LL;
	repn(i, 1, mxN) p[i] = (1LL * p[i - 1] * 10) % MOD;
	for(ll i = n - 1; i >= 0; i--){
		int nm = n - i;
		int d = s[i] - '0';
		v[d] = 1;
		cnt[d][1]++;
		cnt[d][nm]--;
		(ans += ((((d * p[n - i - 1])) % MOD) * (1LL * i * (i + 1) / 2) % MOD) % MOD) %= MOD;
	}
	rep(i, 15) if(v[i]){
		repn(j, 1, mxN) cnt[i][j] += cnt[i][j - 1];
	}
	rep(i, 15) if(v[i]){
		repn(j, 1, n){
			(ans += (((i * p[j - 1]) % MOD) * ((cnt[i][j] * j)) % MOD)) %= MOD;
		}
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
