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
const int mxN = 2e5 + 5;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll mypow(ll a, ll p){
	if(p <= 0) return 1LL;
	if(p & 1) return (a * mypow(a, p - 1)) % MOD;
	ll x = mypow(a, p / 2);
	return sq(x) % MOD;
}

int p[mxN], ls[mxN];

void sieve(int m){
	repn(i, 2, m){
		if(!p[i]) p[i] = i;
		for(int j = i + i; j < m; j += i) if(!p[j]) p[j] = i;
	}
}

int n, q;
ll ans = 1LL;
map<int, int> nm[mxN];
multiset<int> st[mxN];

void add(int i, int x){
	while(x > 1){
		int cr = p[x];
		int rm = nm[i][cr]++;
		auto it = st[cr].find(rm);
		if(it != st[cr].end()) st[cr].erase(it);
		st[cr].insert(rm + 1);
		if(*st[cr].begin() > ls[cr] && (int)(st[cr].size()) == n){
			(ans *= mypow((ll)(cr), (ll)((*st[cr].begin()) - ls[cr]))) %= MOD;
			ls[cr] = *st[cr].begin();
		}
		x /= cr;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> q;
	vi a(n);
	sieve(mxN - 1);
	rep(i, n) cin >> a[i], add(i, a[i]);
	rep(i, q){
		int ind, x;
		cin >> ind >> x;
		add(ind - 1, x);
		cout << ans << '\n';
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
