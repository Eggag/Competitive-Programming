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

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	int nm = 0;
	vi col[35];
	rep(i, n){
		int mn = 1e9;
		int nw = a[i];
		for(int j = 2; (j * j) <= nw; j++){
			while(nw % j == 0){
				nw /= j;
				mn = min(mn, j);
			}
		}
		if(nw > 1) mn = min(mn, nw);
		if(!col[mn].size()) nm++;
		col[mn].pb(i);
	}
	vi ans(n, 0);
	int c = 1;
	rep(i, 35) if(col[i].size()){
		int g = 0;
		rep(j, col[i].size()){
			ans[col[i][j]] = c, g = gcd(g, a[col[i][j]]);
		}
		assert(g > 1);
		c++;
	}
	cout << nm << endl;
	rep(i, ans.size()) cout << ans[i] << " ";
	cout << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
