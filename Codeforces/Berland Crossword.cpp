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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n, u, r, d, l;
	cin >> n >> u >> r >> d >> l;
	rep(i, 1 << 4){
		vi p(4, 0);
		rep(j, 4) if(i & (1 << j)) p[j] = 1;
		int f = 1;
		if(p[0] + p[1] > u || u > (n - 2 + p[0] + p[1])) f = 0;
		if(p[2] + p[1] > r || r > (n - 2 + p[2] + p[1])) f = 0;
		if(p[2] + p[3] > d || d > (n - 2 + p[2] + p[3])) f = 0;
		if(p[0] + p[3] > l || l > (n - 2 + p[0] + p[3])) f = 0;
		if(f){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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
