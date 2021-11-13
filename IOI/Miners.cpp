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
#define inf 0x3f3f3f3f
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[2][4][4][4][4];

void chmax(int &a, int b){
	a = max(a, b);
}

int ch(char c){
	if(c == 'M') return 1;
	if(c == 'F') return 2;
	if(c == 'B') return 3;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(i, 2) rep(j, 4) rep(k, 4) rep(l, 4) rep(m, 4) dp[i][j][k][l][m] = -inf;
	dp[0][0][0][0][0] = 0;
	repn(i, 1, n + 1){
		int cr = i & 1, pr = 1 - cr;
		rep(j, 4) rep(k, 4) rep(l, 4) rep(m, 4){
			vi cnt(4, 0);
			int nm = ch(s[i - 1]);
			cnt[j]++, cnt[k]++;
			cnt[nm]++;
			int cst = (cnt[1] > 0) + (cnt[2] > 0) + (cnt[3] > 0);
			chmax(dp[cr][nm][j][l][m], dp[pr][j][k][l][m] + cst);
			cnt[j]--, cnt[k]--;
			cnt[l]++, cnt[m]++;
			cst = (cnt[1] > 0) + (cnt[2] > 0) + (cnt[3] > 0);
			chmax(dp[cr][j][k][nm][l], dp[pr][j][k][l][m] + cst);
		}
		rep(j, 4) rep(k, 4) rep(l, 4) rep(m, 4) dp[pr][j][k][l][m] = -inf;
	}
	int ans = 0;
	rep(j, 4) rep(k, 4) rep(l, 4) rep(m, 4) ans = max(ans, dp[n & 1][j][k][l][m]);
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
