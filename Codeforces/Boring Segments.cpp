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
const int mxN = 3e5 + 5;
const int mxM = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
array<int, 3> p[mxN];
int h = sizeof(int) * 8 - __builtin_clz(mxM);
int t[2 * mxM], d[mxM];

void apply(int p, int value){
	t[p] += value;
	if(p < mxM) d[p] += value;
}

void build(int p){
	while(p > 1) p >>= 1, t[p] = min(t[p << 1], t[p << 1 | 1]) + d[p];
}

void push(int p){
	for(int s = h; s > 0; --s){
		int i = p >> s;
		if(d[i] != 0){
			apply(i << 1, d[i]);
			apply(i << 1 | 1, d[i]);
			d[i] = 0;
		}
	}
}

void increase(int l, int r, int value){
	l += mxM, r += mxM;
	int l0 = l, r0 = r;
	for(; l < r; l >>= 1, r >>= 1){
		if(l & 1) apply(l++, value);
		if(r & 1) apply(--r, value);
	}
	build(l0);
	build(r0 - 1);
}

int query(int l, int r){
	l += mxM, r += mxM;
	push(l);
	push(r - 1);
	int res = 2e9;
	for(; l < r; l >>= 1, r >>= 1){
		if(l & 1) res = min(res, t[l++]);
		if(r & 1) res = min(t[--r], res);
	}
	return res;
}

bool cmp(array<int, 3> a, array<int, 3> b){
	return a[2] < b[2];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> p[i][0] >> p[i][1] >> p[i][2];
	sort(p, p + n, cmp);
	int ans = 1e6, le = 0;
	memset(t, 0, sizeof(t));
	memset(d, 0, sizeof(d));
	rep(i, n){
		if(i) increase(p[i - 1][0] + (p[i - 1][0] != 1), p[i - 1][1] + 1, -1);
		while(le < n && !query(1, m + 1)){
			increase(p[le][0] + (p[le][0] != 1), p[le][1] + 1, 1);
			le++;
		}
		if(query(1, m + 1)) ans = min(ans, (le == i ? 0 : p[le - 1][2] - p[i][2]));
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
