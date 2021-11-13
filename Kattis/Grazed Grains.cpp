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

ld dist(ld a, ld b, ld a1, ld b1){
	return sqrtl(sq(a - a1) + sq(b - b1));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<ld, ld>> p(n);
	vector<ld> r(n);
	rep(i, n) cin >> p[i].fi >> p[i].se >> r[i];
	ld ans = 0.0;
	for(ld i = -20.0; i <= 20.0; i += 0.01){
		for(ld j = -20.0; j <= 20.0; j += 0.01){
			int f = 0;
			rep(k, n){
				if((dist(i, j, p[k].fi, p[k].se) - r[k]) < 1e-5){
					f = 1;
					break;
				}
			}
			if(f) ans += sq(0.01);
		}
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
