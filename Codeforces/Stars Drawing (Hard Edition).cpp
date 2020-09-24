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

string s[1005];
int up[1005][1005];
int down[1005][1005];
int le[1005][1005];
int ri[1005][1005];
int cntV[1005][1005];
int cntH[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	memset(cntH, 0, sizeof(cntH));
	memset(cntV, 0, sizeof(cntV));
	rep(i, n){
		le[i][0] = (s[i][0] == '*');
		repn(j, 1, m){
			if(s[i][j] == '*') le[i][j] = le[i][j - 1] + 1;
			else le[i][j] = 0;
		}
	}
	rep(i, n){
		ri[i][m - 1] = (s[i][m - 1] == '*');
		for(int j = m - 2; j >= 0; j--){
			if(s[i][j] == '*') ri[i][j] = ri[i][j + 1] + 1;
			else ri[i][j] = 0;
		}
	}
	rep(j, m){
		up[0][j] = (s[0][j] == '*');
		repn(i, 1, n){
			if(s[i][j] == '*') up[i][j] = up[i - 1][j] + 1;
			else up[i][j] = 0;
		}
	}
	rep(j, m){
		down[n - 1][j] = (s[n - 1][j] == '*');
		for(int i = n - 2; i >= 0; i--){
			if(s[i][j] == '*') down[i][j] = down[i + 1][j] + 1;
			else down[i][j] = 0;
		}
	}
	vector<pair<pi, int>> ans;
	repn(i, 1, n - 1) repn(j, 1, m - 1){
		int mn = min({le[i][j], ri[i][j], up[i][j], down[i][j]});
		if(mn > 1){
			ans.pb(mp(mp(i, j), mn - 1));
			cntH[i][j - mn + 1]++;
			cntH[i][j + mn]--;
			cntV[i - mn + 1][j]++;
			cntV[i + mn][j]--;
		}
	}
	rep(i, n) repn(j, 1, m) cntH[i][j] += cntH[i][j - 1];
	rep(j, m) repn(i, 1, n) cntV[i][j] += cntV[i - 1][j];
	rep(i, n) rep(j, m) if(s[i][j] == '*' && !(cntV[i][j] + cntH[i][j])){
		cout << -1 << endl;
		return 0;
	}
	cout << ans.size() << endl;
	for(pair<pi, int> x : ans) cout << x.fi.fi + 1 << " " << x.fi.se + 1 << " " << x.se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
