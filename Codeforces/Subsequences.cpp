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
#define endl '\n'
const int MAXN = (1e5 + 5);

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }


template<class T> struct BIT{
	T bit[MAXN];
	void update(int ind, T delta){
		for(; ind < MAXN; ind += (ind & (-ind))){
			bit[ind] += delta;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ind; ind -= (ind & (-ind))){
			sum += bit[ind];
		}
		return sum;
	}
};

BIT<ll> dp[15];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	k++;
	vi a(n);
	rep(i, n) cin >> a[i];
	if(k == 1){
		cout << n << endl;
		return 0;
	}
	ll ans = 0;
	rep(i, n){
		dp[1].update(a[i], 1);
		repn(j, 2, k + 1){
			ll cur = dp[j - 1].query(a[i] - 1);
			dp[j].update(a[i], cur);
			if(j == k) ans += cur;
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
