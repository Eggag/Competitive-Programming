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
const int MAXN = 1e5 + 5;

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
	int n, m, k;
	cin >> n >> m >> k;
	BIT<ll> bit, bit1;
	vi a(n + 1);
	repn(i, 1, n + 1) cin >> a[i];
	vi l(m), r(m), d(m);
	rep(i, m) cin >> l[i] >> r[i] >> d[i];
	rep(i, k){
		int x, y;
		cin >> x >> y;
		bit.update(x, 1);
		bit.update(y + 1, -1);
	}
	vi h(m + 1, 0);
	repn(i, 1, m + 1) h[i] = bit.query(i);
	rep(i, m){
		bit1.update(l[i], (1LL * d[i] * h[i + 1]));
		bit1.update(r[i] + 1, (1LL * -d[i] * h[i + 1]));
	}
	repn(i, 1, n + 1) cout << a[i] + bit1.query(i) << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
