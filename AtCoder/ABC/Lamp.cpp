#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int up[2005][2005];
int down[2005][2005];
int le[2005][2005];
int ri[2005][2005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	string s[h];
	rep(i, h) cin >> s[i];
	rep(i, 2005) rep(j, 2005) up[i][j] = 0;
	rep(i, 2005) rep(j, 2005) down[i][j] = 0;
	rep(i, h) rep(j, w) if(i){
		up[i][j] = up[i - 1][j] + 1;
		if(s[i - 1][j] == '#') up[i][j] = 0;
		if(s[i][j] == '#') up[i][j] = 0;
	}
	for(int i = h - 2; i >= 0; i--) rep(j, w){
		down[i][j] = down[i + 1][j] + 1;
		if(s[i + 1][j] == '#') down[i][j] = 0;
		if(s[i][j] == '#') down[i][j] = 0;
	}
	rep(i, h) rep(j, w) if(j){
		le[i][j] = le[i][j - 1] + 1;
		if(s[i][j] == '#') le[i][j] = 0;
		if(s[i][j - 1] == '#') le[i][j] = 0;
	}
	rep(i, h) for(int j = w - 2; j >= 0; j--){
		ri[i][j] = ri[i][j + 1] + 1;
		if(s[i][j] == '#') ri[i][j] = 0;
		if(s[i][j + 1] == '#') ri[i][j] = 0;
	}
	int ans = 0;
	rep(i, h) rep(j, w){
		ans = max(ans, down[i][j] + up[i][j] + le[i][j] + ri[i][j] + 1);
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
