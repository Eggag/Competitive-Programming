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
const int mxN = 1e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int p[mxN], pos[mxN];

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

bool cmp(array<int, 4> a, array<int, 4> b){
	return p[a[2] - 1] < p[b[2] - 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) cin >> p[i], pos[p[i]] = i;
	vector<array<int, 4>> q(m);
	rep(i, m) cin >> q[i][0] >> q[i][1] >> q[i][2], q[i][3] = i;
	sort(all(q), cmp);
	vi ans(m, 0);
	BIT<int> bit;
	int lst = 1;
	rep(i, m){
		repn(j, lst, p[q[i][2] - 1] + 1) bit.update(pos[j], 1);
		lst = p[q[i][2] - 1] + 1;
		int l = q[i][0] - 1, r = q[i][1] - 1;
		int res = bit.query(r) - (l ? bit.query(l - 1) : 0) - 1;
		if(res == (q[i][2] - 1) - l) ans[q[i][3]] = 1;
	}
	rep(i, m) cout << (ans[i] ? "Yes" : "No") << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
