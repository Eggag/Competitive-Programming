#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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

ll dp[16][6][6][26][6]; //index, vow, cons, last, same
int gd[30];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int ve, vc, ce, cc;
	cin >> ve >> vc >> ce >> cc;
	string s;
	cin >> s;
	dp[0][0][0][0][0] = 1;
	int n = s.size();
	string ch = "aeiou";
	rep(i, ch.size()) gd[ch[i] - 'a'] = 1;
	repn(i, 1, n + 1){
		char nw = s[i - 1];
		if(nw == '*'){
			rep(cur, 26) rep(j, 5) rep(k, 5) rep(l, 26) rep(m, 6) if(dp[i - 1][j][k][l][m]){
				if(i != 1 && !((!k && j) || (!j && k))) continue;
				//j is vow, k is cons
				int j1 = 0, k1 = 0;
				if(!j && gd[cur]) j1 = 1, k1 = 0;
				if(!j && !gd[cur]) j1 = 0, k1 = k + 1;
				if(!k && !gd[cur]) j1 = 0, k1 = 1;
				if(!k && gd[cur]) j1 = j + 1, k1 = 0;
				int tot = (cur == l ? m + 1 : 1);
				int f = 1;
				if(gd[cur] && (tot > ve || j1 > vc)) f = 0;
				if(!gd[cur] && (tot > ce || k1 > cc)) f = 0;
				if(f) dp[i][j1][k1][cur][tot] += dp[i - 1][j][k][l][m];
			}
		}
		else{
			int cur = (int)(nw - 'a');
			rep(j, 5) rep(k, 5) rep(l, 26) rep(m, 6) if(dp[i - 1][j][k][l][m]){
				if(i != 1 && !((!k && j) || (!j && k))) continue;
				//j is vow, k is cons
				int j1 = 0, k1 = 0;
				if(!j && gd[cur]) j1 = 1, k1 = 0;
				if(!j && !gd[cur]) j1 = 0, k1 = k + 1;
				if(!k && !gd[cur]) j1 = 0, k1 = 1;
				if(!k && gd[cur]) j1 = j + 1, k1 = 0;
				int tot = (cur == l ? m + 1 : 1);
				int f = 1;
				if(gd[cur] && (tot > ve || j1 > vc)) f = 0;
				if(!gd[cur] && (tot > ce || k1 > cc)) f = 0;
				if(f) dp[i][j1][k1][cur][tot] += dp[i - 1][j][k][l][m];
			}
		}
	}
	ll ans = 0LL;
	rep(j, 5) rep(k, 5) rep(l, 26) rep(m, 6) ans += dp[n][j][k][l][m];
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
