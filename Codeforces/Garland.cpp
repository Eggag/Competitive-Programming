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

int dp[105][105][105][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi p(n + 1, 0);
	vi vis(n + 1, 0);
	repn(i, 1, n + 1){
		cin >> p[i];
		if(p[i]) vis[p[i]] = 1;
	}
	int o = 0, e = 0;
	repn(i, 1, n + 1) if(!vis[i]){
		if(i & 1) o++;
		else e++;
	}
	rep(i, 105) rep(j, 105) rep(k, 105) rep(l, 2) dp[i][j][k][l] = 1e9;
	dp[0][e][o][0] = 0;
	dp[0][e][o][1] = 0;
	repn(i, 1, n + 1){
		if(!p[i]){
			rep(j, 104) rep(k, 104){
				if(p[i - 1]){
					dp[i][j][k][0] = min(dp[i - 1][j + 1][k][0], dp[i - 1][j + 1][k][1]) + ((p[i - 1] & 1)); //doesn't matter
					dp[i][j][k][1] = min(dp[i - 1][j][k + 1][0], dp[i - 1][j][k + 1][1]) + (!(p[i - 1] & 1)); 
				}
				else{
					dp[i][j][k][0] = min(dp[i - 1][j + 1][k][1] + 1, dp[i - 1][j + 1][k][0]);
					dp[i][j][k][1] = min(dp[i - 1][j][k + 1][1], dp[i - 1][j][k + 1][0] + 1);
				}
			}
		}
		else{
			rep(j, 105) rep(k, 105) rep(l, 2){
				if(i > 1 && !(p[i - 1])) dp[i][j][k][l] = dp[i - 1][j][k][l] + ((l & 1) != (p[i] & 1));
				else dp[i][j][k][l] = dp[i - 1][j][k][l]; //keep everything
			}
		}
	}
	int add = 0;
	repn(i, 1, n) if(p[i] && p[i + 1] && ((p[i] & 1) != (p[i + 1] & 1))) add++;
	cout << min(dp[n][0][0][0], dp[n][0][0][1]) + add << endl; //has to have no odds left
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
