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
const ld eps = 1e-6;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	ld c, m, p, v;
	cin >> c >> m >> p >> v;
	ld ans = 0.0;
	repn(len, 0, 19){
		ld tot = 0.0;
		rep(j, 1 << len){
			array<ld, 3> a = {c, m, p};
			ld prob = 1.0;
			int f = 1;
			rep(k, len){
				if(j & (1 << k)){
					prob *= a[0];
					if(a[0] > eps){
						if((a[0] - v) > eps){
							a[0] -= v;
							if(a[1] > eps && a[2] > eps){
								a[1] += v / 2;
								a[2] += v / 2;
							}
							else if(a[2] > eps && a[1] < eps){
								a[2] += v;
							}
						}
						else{
							if(a[1] > eps && a[2] > eps){
								a[1] += a[0] / 2;
								a[2] += a[0] / 2;
							}
							else if(a[2] > eps && a[1] < eps){
								a[2] += a[0];
							}
							a[0] = 0;
						}
					}
					else f = 0;
				}
				else{
					prob *= a[1];
					if(a[1] > eps){
						if(a[1] - v > eps){
							a[1] -= v;
							if(a[0] > eps && a[2] > eps){
								a[0] += v / 2;
								a[2] += v / 2;
							}
							else if(a[2] > eps && a[0] < eps){
								a[2] += v;
							}
						}
						else{
							if(a[0] > eps && a[2] > eps){
								a[0] += a[1] / 2;
								a[2] += a[1] / 2;
							}
							else if(a[2] > eps && a[0] < eps){
								a[2] += a[1];
							}
							a[1] = 0;
						}
					}
					else f = 0;
				}
			}
			prob *= a[2];
			if(f) tot += prob;
		}
		ans += tot * (ld)(len + 1);
	}
	cout << fixed << setprecision(15) << ans << '\n';
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
