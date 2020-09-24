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

bool dp[100005][6][6][6];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<string> s(n + 1);
	repn(i, 1, n + 1) cin >> s[i];
	a = min(a, 4);
	b = min(b, 4);
	c = min(c, 4);
	dp[0][a][b][c] = 1;
	repn(i, 1, n + 1) rep(j, 6) rep(k, 6) rep(l, 6){
		if(s[i] == "AB"){
			if(j > 0 && k < 5) dp[i][j - 1][k + 1][l] |= dp[i - 1][j][k][l];
			if(j < 5 && k > 0) dp[i][j + 1][k - 1][l] |= dp[i - 1][j][k][l];
		}
		else if(s[i] == "BC"){
			if(k > 0 && l < 5) dp[i][j][k - 1][l + 1] |= dp[i - 1][j][k][l];
			if(k < 5 && l > 0) dp[i][j][k + 1][l - 1] |= dp[i - 1][j][k][l];
		}
		else{
			if(j > 0 && l < 5) dp[i][j - 1][k][l + 1] |= dp[i - 1][j][k][l];
			if(j < 5 && l > 0) dp[i][j + 1][k][l - 1] |= dp[i - 1][j][k][l];
		}
	}
	int pos = 0;
	pair<pi, int> st;
	rep(i, 6) rep(j, 6) rep(k, 6){
		if(dp[n][i][j][k]) st = mp(mp(i, j), k);
		pos |= dp[n][i][j][k];
	}
	if(pos){
		string ans = "";
		int j = st.fi.fi, k = st.fi.se, l = st.se;
		for(int i = n - 1; i >= 0; i--){
			if(s[i + 1] == "AB"){
				if(j > 0 && k < 5 && dp[i][j - 1][k + 1][l]) ans += 'A', j--, k++;
				else if(j < 5 && k > 0 && dp[i][j + 1][k - 1][l]) ans += 'B', j++, k--;
			}
			else if(s[i + 1] == "BC"){
				if(k > 0 && l < 5 && dp[i][j][k - 1][l + 1]) ans += 'B', k--, l++;
				else if(k < 5 && l > 0 && dp[i][j][k + 1][l - 1]) ans += 'C', k++, l--;
			}
			else{
				if(j > 0 && l < 5 && dp[i][j - 1][k][l + 1]) ans += 'A', l++, j--;
				else if(j < 5 && l > 0 && dp[i][j + 1][k][l - 1]) ans += 'C', j++, l--;
			}
		}
		cout << "Yes" << endl;
		reverse(all(ans));
		rep(i, ans.size()) cout << ans[i] << endl;
	}
	else cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/

