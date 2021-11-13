#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << '\n'
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
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n), bd(n, 0);
	rep(i, k) cin >> a[i], bd[a[i]] = 1;
	vector<array<ld, 2>> cnt(n + m + 1, {0.0, 0.0}), f(n);
	for(int i = n - 1; i >= 0; i--){
		array<ld, 2> cr;
		if(!bd[i]){
			cr[0] = (ld)(1.0 * (cnt[i + 1][0] - cnt[i + 1 + m][0])) / m;
			cr[1] = 1.0 + (ld)(1.0 * (cnt[i + 1][1] - cnt[i + 1 + m][1])) / m;
		}
		else cr = array<ld, 2>{1.0, 0.0};
		cnt[i] = cnt[i + 1];
		cnt[i][0] += cr[0];
		cnt[i][1] += cr[1];
		f[i] = cr;
	}
	if(abs(f[0][0] - 1) < 1e-6) cout << "-1\n";
	else cout << fixed << setprecision(6) << (ld)(-f[0][1] / (ld)(f[0][0] - 1)) << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
