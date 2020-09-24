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

string g[55];
int dp[55][55][55][55];

int go(int x, int y, int x1, int y1){
	if((x == x1) && (y == y1)){
		if(g[x][y] == '#') return 1;
		else return 0;
	}
	int &cur = dp[x][y][x1][y1];
	if(cur != -1) return cur;
	cur = max(x1 - x + 1, y1 - y + 1);
	repn(i, x, x1) cur = min(cur, go(x, y, i, y1) + go(i + 1, y, x1, y1));
	repn(i, y, y1) cur = min(cur, go(x, y, x1, i) + go(x, i + 1, x1, y1));
	return cur;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n) cin >> g[i];
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0, n - 1, n - 1) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
