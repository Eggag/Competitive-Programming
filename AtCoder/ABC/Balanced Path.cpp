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

int a[85][85], b[85][85];
int dp[85][85][10000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	rep(i, h) rep(j, w) cin >> a[i][j];
	rep(i, h) rep(j, w) cin >> b[i][j];
	dp[0][0][abs(a[0][0] - b[0][0])] = 1;
	rep(i, h) rep(j, w){
		if(!i && !j) continue;
		rep(k, 10000){
			if(i) dp[i][j][abs(k - abs(a[i][j] - b[i][j]))] |= dp[i - 1][j][k];
			if(j) dp[i][j][abs(k - abs(a[i][j] - b[i][j]))] |= dp[i][j - 1][k];
			if(i) dp[i][j][abs(k + abs(a[i][j] - b[i][j]))] |= dp[i - 1][j][k];
			if(j) dp[i][j][abs(k + abs(a[i][j] - b[i][j]))] |= dp[i][j - 1][k];
		}
	}
	rep(i, 10000) if(dp[h - 1][w - 1][i]){
		cout << i << endl;
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
