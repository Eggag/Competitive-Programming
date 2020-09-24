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

pi dp[200005];
int p[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	map<int, pi> m;
	rep(i, n){
		dp[i] = {1, -1};
		p[i] = -1;
		if((m[a[i] - 1].fi + 1) > dp[i].fi) dp[i] = {m[a[i] - 1].fi + 1, m[a[i] - 1].se}, p[i] = m[a[i] - 1].se;
		if(dp[i].fi > m[a[i]].fi) m[a[i]] = mp(dp[i].fi, i);
	}
	int ans = 0;
	int bst = -1;
	rep(i, n){
		if(dp[i].fi > ans){
			ans = dp[i].fi;
			bst = i;
		}
		ans = max(ans, dp[i].fi);
	}
	cout << ans << endl;
	vi res;
	while(bst != -1){
		res.pb(bst);
		bst = p[bst];
	}
	reverse(all(res));
	rep(i, res.size()) cout << res[i] + 1 << " ";
	cout << endl;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
