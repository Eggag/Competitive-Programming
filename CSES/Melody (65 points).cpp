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
const int mxN = 5005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[mxN][mxN];
pi dp[mxN][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, S, G;
	cin >> n >> S >> G;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int l;
	cin >> l;
	vi a(l + 1);
	repn(i, 1, l + 1) cin >> a[i], a[i]--;
	rep(i, n) rep(j, n){ //to speed up transitions
		int num = 0;
		rep(k, S) if(s[i][k] != s[j][k]) num++;
		g[i][j] = (int)(num <= G);
	}
	rep(i, l + 1) rep(j, n) dp[i][j] = {1e9, -1};
	dp[0][0] = {0, -1};
	repn(i, 1, l + 1){
		rep(j, n) rep(k, n){ //j is prev, k is cur
			if((dp[i - 1][j].fi + (k != a[i])) < dp[i][k].fi && (i == 1 || g[j][k])){
				dp[i][k] = {dp[i - 1][j].fi + (k != a[i]), j};
			}
		}
	}
	//find the min and do a reconstruction
	int mn = 1e9, bst = -1;
	rep(i, n){
		if(dp[l][i].fi < mn){
			mn = dp[l][i].fi;
			bst = i;
		}
	}
	cout << mn << endl;
	assert(bst != -1);
	vi ans = {bst};
	int nxt = dp[l][bst].se;
	int ind = l - 1;
	while(nxt != -1 && ind){
		ans.pb(nxt);
		nxt = dp[ind][nxt].se;
		ind--;
	}
	reverse(all(ans));
	rep(i, ans.size()) cout << ans[i] + 1 << " ";
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
