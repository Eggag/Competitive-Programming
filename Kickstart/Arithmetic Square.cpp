#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

int g[3][3];

int solve(){
	rep(i, 3){
		rep(j, 3){
			if(i == 1 && j == 1) g[i][j] = 0;
			else cin >> g[i][j];
		}
	}
	int ans = 0;
	map<int, int> cr;
	if(g[0][1] - g[0][0] == g[0][2] - g[0][1]) ans++;
	if(g[2][1] - g[2][0] == g[2][2] - g[2][1]) ans++;
	if(g[1][0] - g[0][0] == g[2][0] - g[1][0]) ans++;
	if(g[1][2] - g[0][2] == g[2][2] - g[1][2]) ans++;
	int add = 0;
	if((g[1][2] - g[1][0]) % 2 == 0){
		int dif = abs((g[1][2] - g[1][0]) / 2);
		add = max(add, ++cr[max(g[1][2], g[1][0]) - dif]);
	}
	if((g[2][1] - g[0][1]) % 2 == 0){
		int dif = abs((g[2][1] - g[0][1]) / 2);
		add = max(add, ++cr[max(g[2][1], g[0][1]) - dif]);
	}
	if((g[2][2] - g[0][0]) % 2 == 0){
		int dif = abs((g[2][2] - g[0][0]) / 2);
		add = max(add, ++cr[max(g[2][2], g[0][0]) - dif]);
	}
	if((g[0][2] - g[2][0]) % 2 == 0){
		int dif = abs((g[0][2] - g[2][0]) / 2);
		add = max(add, ++cr[max(g[0][2], g[2][0]) - dif]);
	}
	return ans + add;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
