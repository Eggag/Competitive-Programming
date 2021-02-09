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
#define inf 0x3f3f3f3f
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int mn[mxN], mn1[mxN];

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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w, m;
	cin >> h >> w >> m;
	vi x(m), y(m);
	BIT<int> bit;
	rep(i, mxN) mn[i] = h + 1, mn1[i] = w + 1;
	rep(i, m){
		cin >> x[i] >> y[i];
		mn[y[i]] = min(mn[y[i]], x[i]);
		mn1[x[i]] = min(mn1[x[i]], y[i]);
	}
	ll ans = 1LL;
	int mx = w + 1;
	repn(i, 2, w + 1){
		if(mn[i] == 1){
			mx = i;
			break;
		}
		ans += mn[i] - 1;
	}
	vector<pi> q;
	repn(i, 2, h + 1){
		if(mn1[i] == 1) break;
		q.pb({mn1[i], i});
	}
	sort(all(q));
	int cr = 2;
	rep(i, q.size()){
		while(cr < (q[i].fi)) bit.update(mn[cr], (cr <= mx ? 1 : 0)), cr++;
		ans += mn1[q[i].se] - (bit.query(mxN - 1) - bit.query(q[i].se)) - 1;
	}
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
