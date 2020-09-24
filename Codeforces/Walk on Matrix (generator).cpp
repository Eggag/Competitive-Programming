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

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

const int n = 3, m = 3;

int a[n][m];
int mx = 0;

void dfs(int i, int j, int cur){
	if(i == n - 1 && j == m - 1){
		mx = max(mx, cur);
		return;
	}
	if((i + 1) < n) dfs(i + 1, j, cur & a[i + 1][j]);
	if((j + 1) < m) dfs(i, j + 1, (cur & a[i][j + 1]));
}

int solve1(){
	mx = 0;
	dfs(0, 0, a[0][0]);
	return mx;
}

int dp[n][m];

int solve2(){
	rep(i, n) rep(j, m) dp[i][j] = 0;
	dp[0][0] = a[0][0];
	rep(i, n) rep(j, m){
		if(i) dp[i][j] = max(dp[i][j], dp[i - 1][j] & a[i][j]);
		if(j) dp[i][j] = max(dp[i][j], dp[i][j - 1] & a[i][j]);
	}
	return dp[n - 1][m - 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	while(true){
		/*
		rep(i, n) rep(j, m){
			a[i][j] = rng() % 10;
		}
		*/
		a[0][0] = 262143;
		a[0][1] = 1;
		a[0][2] = 0;
		a[1][0] = 131072;
		a[1][1] = 131073;
		a[1][2] = 1;
		a[2][0] = 0;
		a[2][1] = 131072;
		a[2][2] = 1;
		debug2(solve1(), solve2());
		return 0;
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
