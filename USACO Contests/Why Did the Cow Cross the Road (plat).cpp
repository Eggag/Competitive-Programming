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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[mxN], b[mxN], pos[mxN], pos1[mxN];

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(mxN, 0);
	}
	void update(int ind, T delta){
		for(; ind < mxN; ind = ind | (ind + 1)){
			bit[ind] += delta;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ind >= 0; ind = (ind & (ind + 1)) - 1){
			sum += bit[ind];
		}
		return sum;
	}
};

ll solve(){
	ll tot = 0LL;
	BIT<ll> bit;
	rep(i, n) pos[b[i]] = i;
	rep(i, n) pos1[a[i]] = i;
	rep(i, n){
		ll num = pos[a[i]];
		tot += num - 2 * (pos[a[i]] ? bit.query(pos[a[i]] - 1) : 0) + i;
		bit.update(pos[a[i]], 1);
	}
	tot /= 2;
	ll mn = tot;
	for(int i = n - 1; i >= 0; i--){
		tot -= n - 1 - pos1[b[i]];
		tot += pos1[b[i]];
		mn = min(mn, tot);
	}
	return mn;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("mincross.in", "r", stdin);
	freopen("mincross.out", "w", stdout);
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	/*
	rep(i, n) cout << a[i] << " ";
	cout << endl;
	rep(i, n) cout << b[i] << " ";
	cout << endl;
	*/
	ll ans = solve();
	swap(a, b);
	ans = min(ans, solve());
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
