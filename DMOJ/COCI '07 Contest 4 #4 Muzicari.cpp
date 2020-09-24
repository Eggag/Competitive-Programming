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

vi dp[5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t, n;
	cin >> t >> n;
	vi a(n);
	int sum = 0;
	rep(i, n) cin >> a[i], sum += a[i];
	rep(i, n){
		for(int j = t - a[i]; j >= 0; j--){
			if(!j || (j && dp[j].size())){
				dp[j + a[i]] = dp[j];
				dp[j + a[i]].pb(i);
			}
		}
	}
	int bst = -1;
	for(int j = t; j >= 1; j--) if(dp[j].size()){
		bst = j;
		break;
	}
	vi ans(n);
	vi vis(n, 0);
	int cur = 0;
	rep(i, dp[bst].size()){
		ans[dp[bst][i]] = cur;
		cur += a[dp[bst][i]];
		vis[dp[bst][i]] = 1;
	}
	assert(bst != -1);
	assert((sum - bst) <= t);
	cur = 0;
	rep(i, n) if(!vis[i]){
		ans[i] = cur;
		cur += a[i];
	}
	rep(i, n) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
