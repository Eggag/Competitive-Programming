#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int dp[65][65][65];
int w[3] = {9, 3, 1};

struct MutaliskEasy{
	int dfs(int a, int b, int c){
		a = max(0, a), b = max(0, b), c = max(0, c);
		if(a == 0 && b == 0 && c == 0) return 0;
		if(dp[a][b][c]) return dp[a][b][c];
                //not necessary, but executes faster since the order doesn't matter
		if(dp[a][c][b]) return dp[a][c][b];
		if(dp[b][a][c]) return dp[b][a][c];
		if(dp[b][c][a]) return dp[b][c][a];
		if(dp[c][b][a]) return dp[c][b][a];
		if(dp[c][a][b]) return dp[c][a][b];
		int m = INT_MAX;
		rep(x, 3) rep(y, 3) rep(z, 3) if(x != y && y != z && x != z){
			m = min(m, dfs(a - w[x], b - w[y], c - w[z]));
		}
		dp[a][b][c] = 1 + m;
		return dp[a][c][b] = dp[b][a][c] = dp[b][c][a] = dp[c][b][a] = dp[c][a][b] = dp[a][b][c];
	}
	int minimalAttacks(vi a){
             	ios_base::sync_with_stdio(false);
	       	cin.tie(0);
		int n = a.size();
		vi x = {0, 0, 0};
		rep(i, n) x[i] = a[i];
		return dfs(x[0], x[1], x[2]);
	}
};
/*
Things to look out for:
        - Integer overflows
        - Array bounds
        - Special cases
Be careful!
*/