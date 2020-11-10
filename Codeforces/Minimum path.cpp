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
const int mxN = 2005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

string s[mxN];
pair<int, char> dp[mxN][mxN];
char lev[2 * mxN], be[mxN][mxN];
int p[mxN][mxN]; //1 is left, 2 is right
int vis[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	rep(i, n) cin >> s[i];
	queue<array<int, 2>> q;
	rep(i, n) rep(j, n) dp[i][j] = {0, '|'};
	rep(i, 2 * mxN) lev[i] = '|';
	rep(i, n) rep(j, n) be[i][j] = '|';
	dp[0][0].fi = k;
	dp[0][0].se = 'a';
	if(s[0][0] == 'a') q.push({0, 0});
	else{
		if(k) q.push({0, 0}), dp[0][0].fi--;
		else q.push({0, 0}), dp[0][0].se = s[0][0];
	}
	vis[0][0] = 1;
	while(!q.empty()){
		array<int, 2> cur = q.front();
		q.pop();
		int x = cur[0], y = cur[1];
		if((x + y) > 0 && dp[x][y].se > lev[x + y]) continue;
		if(x < (n - 1)){
			if(dp[x][y].se == 'a' && dp[x][y].fi){
				//the case where we can expand on the a's
				int nw = dp[x][y].fi - (s[x + 1][y] != 'a');
				if(nw >= dp[x + 1][y].fi){
					dp[x + 1][y].fi = nw;
					dp[x + 1][y].se = 'a';
					p[x + 1][y] = 1;
					if(!vis[x + 1][y]) q.push({x + 1, y});
					be[x + 1][y] = 'a';
					lev[x + 1 + y] = min(lev[x + 1 + y], 'a');
					vis[x + 1][y] = 1;
				}
			}
			else{
				if(dp[x][y].se < be[x + 1][y]){
					p[x + 1][y] = 1;
					be[x + 1][y] = dp[x][y].se;
					dp[x + 1][y].se = s[x + 1][y];
					lev[x + 1 + y] = min(lev[x + 1 + y], dp[x + 1][y].se);
					if(!vis[x + 1][y]) q.push({x + 1, y});
					vis[x + 1][y] = 1;
				}
			}
		}
		if(y < (n - 1)){
			if(dp[x][y].se == 'a' && dp[x][y].fi){
				//the case where we can expand on the a's
				int nw = dp[x][y].fi - (s[x][y + 1] != 'a');
				if(nw >= dp[x][y + 1].fi){
					dp[x][y + 1].fi = nw;
					dp[x][y + 1].se = 'a';
					p[x][y + 1] = 2;
					if(!vis[x][y + 1]) q.push({x, y + 1});
					be[x][y + 1] = 'a';
					lev[x + 1 + y] = min(lev[x + 1 + y], 'a');
					vis[x][y + 1] = 1;
				}
			}
			else{
				if(dp[x][y].se < be[x][y + 1]){
					p[x][y + 1] = 2;
					be[x][y + 1] = dp[x][y].se;
					dp[x][y + 1].se = s[x][y + 1];
					lev[x + 1 + y] = min(lev[x + 1 + y], dp[x][y + 1].se);
					if(!vis[x][y + 1]) q.push({x, y + 1});
					vis[x][y + 1] = 1;
				}
			}
		}
	}
	int x = n - 1, y = n - 1;
	int pr = p[x][y];
	string ans = "";
	ans += s[n - 1][n - 1];
	while(pr){
		if(pr == 1) x--;
		else y--;
		ans += s[x][y];
		pr = p[x][y];
	}
	reverse(all(ans));
	int rem = k;
	rep(i, ans.size()){
		if(!rem) break;
		if(ans[i] != 'a') ans[i] = 'a', rem--;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
