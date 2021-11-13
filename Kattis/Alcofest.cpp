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
	int n, k;
	cin >> n >> k;
	vector<pi> p(n);
	vector<pi> p1;
	rep(i, n){
		cin >> p[i].fi >> p[i].se;
		p1.pb(mp(p[i].fi, 0));
		p1.pb(mp(p[i].se, 1));
	}
	sort(all(p1));
	int ans = 0, cr = 0, l = 0;
	rep(i, 2 * n){
		if(!p1[i].se){
			cr++;
			while(p1[i].fi - k > p1[l].fi){
				if(p1[l].se) cr--;
				l++;
			}
			ans = max(ans, cr);
		}
		else{
			while(p1[i].fi - k > p1[l].fi){
				if(p1[l].se) cr--;
				l++;
			}
			ans = max(ans, cr);
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
