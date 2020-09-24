#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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
	int n, l, r, x;
	cin >> n >> l >> r >> x;
	vi c(n);
	rep(i, n) cin >> c[i];
	int ans = 0;
	rep(i, (1 << n)) if(__builtin_popcount(i) >= 2){
		int cur = 0;
		int mx = 0, mn = 1e9;
		rep(j, n){
			if(i & (1 << j)){
				cur += c[j];
				mx = max(mx, c[j]);
				mn = min(mn, c[j]);
			}
		}
		if(cur >= l && cur <= r){
			if((mx - mn) >= x) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
