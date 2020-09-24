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
const int mxN = 2e5 + 5;
const int MOD = 998244353;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct BIT{
	vector<ll> bit;
	BIT(){
		bit.assign(mxN, 0LL);
	}
	void update(int ind, ll val){
		for(; ind < mxN; ind += (ind & (-ind))) bit[ind] += val;
	}
	ll query(int ind){
		ll ret = 0LL;
		for(; ind; ind -= (ind & (-ind))) ret += bit[ind];
		return ret;
	}
};

ll dp[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi l(k), r(k);
	rep(i, k) cin >> l[i] >> r[i];
	dp[1] = 1;
	BIT bit;
	repn(i, 1, n + 1){
		if(i != 1) dp[i] = (bit.query(i) + MOD) % MOD;
		rep(j, k) if(i + l[j] <= n){
			bit.update(i + l[j], dp[i]);
			bit.update(i + r[j] + 1, -dp[i]);
		}
	}
	cout << (dp[n] + MOD) % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
