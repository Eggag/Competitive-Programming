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

ll hsh[2][200005];
ll pows[2][200005];
ll MOD = 1e9 + 7, MOD2 = 1e9 + 9;

int n;

pair<ll, ll> comp_hs(int l, int r){
	ll h1 = (((hsh[0][r] - hsh[0][l - 1] * pows[0][(r - l + 1)]) % MOD) + MOD) % MOD;
	ll h2 = (((hsh[1][r] - hsh[1][l - 1] * pows[1][(r - l + 1)]) % MOD2) + MOD2) % MOD2;
	return mp(h1, h2);
}

bool check(int len){
	int ind = 0;
	vector<pair<ll, ll>> pos;
	repn(i, len - 1, n){
		pair<ll, ll> cr = comp_hs(ind + 1, i + 1);
		pos.pb(cr);
		ind++;
	}
	sort(all(pos));
	repn(i, 1, pos.size()) if(pos[i] == pos[i - 1]) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	string s;
	cin >> s;
	pows[0][0] = pows[1][0] = 1;	
	for(int i = 1; i <= n; i++){
		pows[0][i] = (pows[0][i - 1] * 37) % MOD;
		pows[1][i] = (pows[1][i - 1] * 131) % MOD2;
	}
	for(int i = 1; i <= n; i++){
		hsh[0][i] = (hsh[0][i - 1] * 37) + (ll)(s[i - 1] - 'a') + 1;
		hsh[1][i] = (hsh[1][i - 1] * 131) + (ll)(s[i - 1] - 'a') + 1;
		hsh[0][i] %= MOD;
		hsh[1][i] %= MOD2;
	}
	int l = 0, r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
