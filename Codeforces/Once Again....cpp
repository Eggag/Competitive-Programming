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

int dp[50005][305];
int cnt[305];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, t;
	cin >> n >> t;
	vi a(n);
	rep(i, n) cin >> a[i], cnt[a[i]]++;
	if((n * t) <= 3e4){
		rep(j, t - 1) rep(i, n) a.pb(a[i]);
		int ans = 1;
		rep(i, 305) dp[0][i] = 0;
		dp[0][a[0]] = 1;
		repn(i, 1, a.size()){
			rep(j, 305) dp[i][j] = dp[i - 1][j];
			rep(j, a[i] + 1) dp[i][a[i]] = max(dp[i][a[i]], dp[i - 1][j] + 1), ans = max(ans, dp[i][a[i]]);
		}
		cout << ans << endl;
	}
	else{
		int ans = 1;
		repn(i, 1, 305) if(cnt[i]){
			int cur = (t - 200) * cnt[i];
			vi b;
			int num = 0;
			rep(j, 100) rep(k, n) b.pb(a[k]), num += (a[k] == i);
			rep(j, n){
				if(a[j] == i) break;
				else b.pb(a[j]);
			}
			int bst = num;
			rep(j, i + 1) dp[0][j] = 0;
			if(b[0] <= i) dp[0][b[0]] = 1;
			if(b[0] == i) num--;
			else if(b[0] < i) bst++;
			int nw = 0;
			repn(j, 1, b.size()){
				rep(k, 305) dp[j][k] = dp[j - 1][k];
				if(b[j] <= i) rep(k, min(i, b[j]) + 1) dp[j][b[j]] = max(dp[j][b[j]], dp[j - 1][k] + 1), nw = max(nw, dp[j][b[j]]);
				if(b[j] == i) num--;
				bst = max(bst, nw + num);
			}
			b.clear();
			int num1 = 0;
			for(int j = n - 1; j >= 0; j--){
				if(a[j] == i) break;
				else b.pb(a[j]);
			}
			reverse(all(b));
			rep(j, 100) rep(k, n) b.pb(a[k]), num1 += (a[k] == i);
			rep(j, 305) dp[(int)b.size() - 1][j] = 0;
			int bst1 = num1;
			if(b[b.size() - 1] >= i){
				dp[b.size() - 1][b[b.size() - 1]] = 1;
				if(b[b.size() - 1] != i) bst1++;
				else num1--;
			}
			int nw1 = 0;
			for(int j = b.size() - 2; j >= 0; j--){
				repn(k, i, 305) dp[j][k] = dp[j + 1][k];
				int cur1 = b[j];
				if(b[j] >= i){
					repn(k, cur1, 305) dp[j][cur1] = max(dp[j][cur1], dp[j + 1][k] + 1), nw1 = max(nw1, dp[j][cur1]);
				}
				if(cur1 == i) num1--;
				bst1 = max(bst1, nw1 + num1);
			}
			ans = max(ans, cur + bst + bst1);
		}
		cout << ans << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
