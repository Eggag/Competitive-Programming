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
	int n, l, r;
	cin >> n >> l >> r;
	vi c(n);
	rep(i, n) cin >> c[i];
	vi ri(n + 1, 0), le(n + 1, 0);
	rep(i, l) le[c[i]]++;
	repn(i, l, n) ri[c[i]]++;
	if(l < r){
		int ans = r - (n / 2);
		rep(i, l){
			if(ri[c[i]]) ri[c[i]]--;
			else ans++;
		}
		int nm = (n / 2) - l;
		repn(i, 1, n + 1){
			nm -= ri[i] / 2; 
		}
		cout << ans + max(0, nm) << '\n';
	}
	else{
		int ans = l - (n / 2);
		repn(i, l, n){
			if(le[c[i]]) le[c[i]]--;
			else ans++;
		}
		int nm = (n / 2) - r;
		repn(i, 1, n + 1){
			nm -= le[i] / 2; 
		}
		cout << ans + max(0, nm) << '\n';
	}
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
