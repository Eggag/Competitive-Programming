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

int d[50][50], g[1005][1005];
int cost[5][50];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, c;
	cin >> n >> c;
	rep(i, c) rep(j, c) cin >> d[i][j];
	repn(i, 1, n + 1) repn(j, 1, n + 1) cin >> g[i][j], g[i][j]--;
	rep(i, 5) rep(j, 50) cost[i][j] = 0;
	//so there are 3 components in the grid based on the modulo of the sum of coords.
	int ans = 1e9;
	repn(i, 1, n + 1) repn(j, 1, n + 1){
		int md = (i + j) % 3;
		rep(k, c) cost[md][k] += d[g[i][j]][k];
	}
	rep(i, c) rep(j, c) rep(k, c) if(i != j && i != k && j != k){
		ans = min(ans, cost[0][i] + cost[1][j] + cost[2][k]);
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
