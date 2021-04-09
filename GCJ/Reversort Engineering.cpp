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
const int mxN = 1005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int pos[mxN];
vi dp[mxN];

void solve(){
	int n, c;
	cin >> n >> c;
	if(c < (n - 1)){
		cout << "IMPOSSIBLE\n";
		return;
	}
	memset(pos, 0, sizeof(pos));
	rep(i, mxN) dp[i].clear();
	pos[0] = 1;
	c -= n - 1;
	repn(i, 1, n){
		for(int j = c - i; j >= 0; j--) if(pos[j]){
			dp[j + i] = dp[j];
			dp[j + i].pb(i);
			pos[j + i] = 1;
		}
	}
	if(!pos[c]){
		cout << "IMPOSSIBLE\n";
		return;
	}
	vi ans(n);
	rep(i, n) ans[i] = i;
	for(int x : dp[c]){
		reverse(ans.begin() + (n - 1) - x, ans.end());
	}
	rep(i, n){
		cout << ans[i] + 1;
		if(i != (n - 1)) cout << " ";
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
