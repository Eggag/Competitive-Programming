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
const int mxN = 205;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

array<int, 3> dp[mxN * 2][mxN][mxN][2];

int fn(char c){
	if(c == '(') return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	rep(i, mxN * 2) rep(j, mxN) rep(k, mxN) rep(l, 2) dp[i][j][k][l] = array<int, 3>{(int)-1e9, -1, -1};
	dp[0][0][0][0] = dp[0][0][0][1] = array<int, 3>{0, -1, -1};
	repn(i, 1, mxN * 2){
		rep(bal, min(i, mxN - 1)) rep(j, n + 1) rep(k, 2) rep(l, 2){
			array<int, 3> cr = dp[i - 1][bal][j][k];
			if(cr[0] == -1e9) continue;
			int bal1 = bal;
			if(!l) bal1++;
			else bal1--;
			if(bal1 < 0) continue;
			int f = j;
			if(j != n) f = j + (fn(s[j]) == l);
			int s = cr[0];
			if(cr[0] != m) s = cr[0] + (fn(t[cr[0]]) == l);
			if(s > dp[i][bal1][f][l][0]){
				dp[i][bal1][f][l] = {s, j, k};
			}
		}
	}
	int mn = 1e9;
	rep(i, mxN * 2) rep(bal, mxN - 1) rep(j, 2){
		array<int, 3> cur = dp[i][bal][n][j];
		if(cur[0] == m && !bal) mn = min(mn, i);
	}
	string ans = "";
	rep(i, mxN * 2) rep(bal, mxN - 1) rep(j, 2){
		array<int, 3> cur = dp[i][bal][n][j];
		if(cur[0] == m && !bal && i == mn){
			array<int, 4> st = {i, bal, n, j};
			while(st[0] > 0){
				if(st[3]) ans += ')';
				else ans += '(';
				array<int, 3> d = dp[st[0]][st[1]][st[2]][st[3]];
				st[0]--;
				if(st[3]) st[1]++;
				else st[1]--;
				st[2] = d[1];
				st[3] = d[2];
			}
			reverse(all(ans));
			cout << ans << '\n';
			return 0;
		}
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
