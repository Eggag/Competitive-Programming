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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	vi a(6);
	rep(i, 6) cin >> a[i];
	int n;
	cin >> n;
	vi b(n);
	rep(i, n) cin >> b[i];
	sort(all(a));
	sort(all(b));
	int bst = 2e9 + 10;
	vector<pi> p;
	rep(j, 6) rep(i, n) p.pb({b[i] - a[j], i});
	sort(all(p));
	vi cr(n, 5);
	int mn = 2e9, mx = -2e9;
	rep(i, 6 * n){
		mn = p[i].fi;
		if(!i){
			rep(j, n) for(int k = 5; k >= 0; k--){
				if(b[j] - a[k] >= mn){
					mx = max(mx, b[j] - a[k]);
					break;
				}
			}
		}
		else{
			int pr = p[i - 1].se;
			cr[pr]--;
			if(cr[pr] < 0) break;
			mx = max(mx, b[pr] - a[cr[pr]]);
		}
		bst = min(bst, mx - mn);
	}
	cout << bst << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
