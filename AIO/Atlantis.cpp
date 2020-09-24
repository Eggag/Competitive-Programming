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
const int dx1[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy1[8] = {1, -1, 1, 0, -1, 1, 0, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int r, c, f, h;
int g[105][105];
int dp[105][105];

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < r && j < c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("atlanin.txt", "r", stdin);
	freopen("atlanout.txt", "w", stdout);
	cin >> h >> f;
	cin >> r >> c;
	rep(i, r) rep(j, c) cin >> g[i][j];
	rep(i, r) rep(j, c) dp[i][j] = 1e9;
	rep(i, r) dp[i][0] = g[i][0];
	rep(j, c) dp[0][j] = g[0][j];
	rep(i, r) dp[i][c - 1] = g[i][c - 1];
	rep(j, c) dp[r - 1][j] = g[r - 1][j];
	rep(_, 150) rep(i, r) rep(j, c){
		rep(k, 8){
			int x = i + dx1[k], y = j + dy1[k];
			if(valid(x, y)){
				dp[x][y] = min(dp[x][y], max(dp[i][j], g[x][y]));
			}
		}
	}
	int ans = 0;
	rep(i, r){
		rep(j, c){
			if(dp[i][j] <= h && (g[i][j] < f || (dp[i][j] > g[i][j]))) ans++;	
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
