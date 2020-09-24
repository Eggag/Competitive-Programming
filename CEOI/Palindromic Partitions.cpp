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

ll hsh[2][1000005]; //change bounds if necessary
ll pows[2][1000005];
ll MOD = 1e9 + 7, MOD2 = 1e9 + 9;

pair<ll, ll> comp_hs(int l, int r){ //1 indexed
	ll h1 = (((hsh[0][r] - hsh[0][l - 1] * pows[0][(r - l + 1)]) % MOD) + MOD) % MOD;
	ll h2 = (((hsh[1][r] - hsh[1][l - 1] * pows[1][(r - l + 1)]) % MOD2) + MOD2) % MOD2;
	return mp(h1, h2);
}

string s;
int n;

int solve(int l, int r){
	if(l == r) return 1;
	if(r < l) return 0;
	int nm = (r - l + 2) / 2;
	rep(i, nm){
		pair<ll, ll> c = comp_hs(l + 1, l + i + 1);
		pair<ll, ll> c1 = comp_hs(r - i + 1, r + 1);
		if(c == c1){
			return 2 + solve(l + 1 + i, r - 1 - i);
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		n = (int)s.size();
		pows[0][0] = pows[1][0] = 1;
		for(int i = 1; i <= n; i++){
			pows[0][i] = (pows[0][i - 1] * 179) % MOD;
			pows[1][i] = (pows[1][i - 1] * 131) % MOD2;
		}
		for(int i = 1; i <= n; i++){
			hsh[0][i] = (hsh[0][i - 1] * 179) + (ll)(s[i - 1] - 'a') + 1;
			hsh[1][i] = (hsh[1][i - 1] * 131) + (ll)(s[i - 1] - 'a') + 1;
			hsh[0][i] %= MOD;
			hsh[1][i] %= MOD2;
		}
		cout << solve(0, n - 1) << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
