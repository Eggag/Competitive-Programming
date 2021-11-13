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
const int logn = 22;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ll a[mxN];
ll gc[logn][mxN];

ll GCD(int l, int r){ // [l; r)
	int t = __lg(r - l);
	return gcd(gc[t][l], gc[t][r - (1 << t)]);
}

bool check(int g){
	rep(i, n - g) if(GCD(i, i + g) != 1) return 1;
	return 0;
}

void solve(){
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n - 1) gc[0][i] = abs(a[i + 1] - a[i]);
	for(int l = 0; l < logn - 1; l++){
		for(int i = 0; i + (2 << l) < n; i++){
			gc[l + 1][i] = gcd(gc[l][i], gc[l][i + (1 << l)]);
		}
	}
	int l = 0, r = n - 1;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l + 1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
