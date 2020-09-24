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
const int MAXN = 2e5 + 1;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(MAXN, 0);
	}
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	BIT<int> bit;
	vi a(n + 1);
	repn(i, 1, n + 1) cin >> a[i];
	sort(all(a));
	reverse(all(a));
	rep(i, q){
		int l, r;
		cin >> l >> r;
		bit.update(l, 1);
		bit.update(r + 1, -1);
	}
	vi ans(n + 1);
	repn(i, 1, n + 1) ans[i] = bit.query(i);
	sort(all(ans));
	reverse(all(ans));
	ll an = 0;
	rep(i, n) an += (1LL * ans[i] * a[i]);
	cout << an << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
