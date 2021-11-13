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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<array<ld, 2>> p(n);
	rep(i, n) cin >> p[i][0] >> p[i][1];
	ld ans = 1e18;
	rep(i, n){
		int j = (i + 1) % n;
		int k = (i + 2) % n;
		swap(i, j);
		ld tp = abs((p[k][0] - p[j][0]) * (p[j][1] - p[i][1]) - (p[j][0] - p[i][0]) * (p[k][1] - p[j][1]));
		ld ds = tp / sqrtl(sq(p[k][0] - p[j][0]) + sq(p[k][1] - p[j][1]));
		swap(i, j);
		ans = min(ans, (ld)(ds / 2.0));
	}
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
