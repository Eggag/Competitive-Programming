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

int h, w;
string s[405];
int vis[405][405];
int ind[405][405];
int W[200005];
int nm;

void dfs(int i, int j){
	if(vis[i][j]) return;
	vis[i][j] = 1;
	ind[i][j] = nm;
	if(s[i][j] == '.') W[nm]++;
	if(i < (h - 1) && s[i + 1][j] != s[i][j]) dfs(i + 1, j);
	if(j < (w - 1) && s[i][j + 1] != s[i][j]) dfs(i, j + 1);
	if(i > 0 && s[i - 1][j] != s[i][j]) dfs(i - 1, j);
	if(j > 0 && s[i][j - 1] != s[i][j]) dfs(i, j - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> h >> w;
	rep(i, h) cin >> s[i];
	nm = 0;
	rep(i, h) rep(j, w) if(!vis[i][j]){
		nm++;
		dfs(i, j);
	}
	ll ans = 0;
	rep(i, h) rep(j, w) if(s[i][j] == '#') ans += W[ind[i][j]];
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
