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
const int mxN = 505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int ans[mxN][mxN];

void solve(){
	int n, k;
	cin >> n >> k;
	vi o, e;
	repn(i, 1, (n * k) + 1){
		if(i & 1) o.pb(i);
		else e.pb(i);
	}
	reverse(all(o));
	reverse(all(e));
	if((int)(o.size()) % k == 0){
		cout << "YES\n";
		rep(i, n){
			rep(j, k){
				if(o.size()){
					ans[i][j] = o.back();
					o.pop_back();
				}
				else if(e.size()){
					ans[i][j] = e.back();
					e.pop_back();
				}
			}
		}
		rep(i, n){
			rep(j, k) cout << ans[i][j] << ' ';
			cout << '\n';
		}
	}
	else cout << "NO\n";
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
