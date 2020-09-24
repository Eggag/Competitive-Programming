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

int n, m, k;
string s[1005];
int vis[1005][1005];
int c[1005][1005];
int comp = 0;
int ans[1000005];

void dfs(int i, int j){
	vis[i][j] = 1;
	c[i][j] = comp;
	if((i + 1) < n && !vis[i + 1][j] && s[i + 1][j] == '.') dfs(i + 1, j);
	if((i - 1) >= 0 && !vis[i - 1][j] && s[i - 1][j] == '.') dfs(i - 1, j);
	if((j + 1) < m && !vis[i][j + 1] && s[i][j + 1] == '.') dfs(i, j + 1);
	if((j - 1) >= 0 && !vis[i][j - 1] && s[i][j - 1] == '.') dfs(i, j - 1);
	if((i + 1) < n && s[i + 1][j] == '*') ans[comp]++;
	if((i - 1) >= 0 && s[i - 1][j] == '*') ans[comp]++;
	if((j + 1) < m && s[i][j + 1] == '*') ans[comp]++;
	if((j - 1) >= 0 && s[i][j - 1] == '*') ans[comp]++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> k;
	//we are looking at connected components in the grid
	//dude, these are some quality problems!
	rep(i, n) cin >> s[i];
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	rep(i, n) rep(j, m) if(!vis[i][j] && s[i][j] == '.'){
		dfs(i, j);
		comp++;
	}
	/*
	rep(i, n){
		rep(j, m){
			if(s[i][j] == '*') cout << s[i][j];
			else cout << c[i][j];
		}
		cout << endl;
	}
	*/
	rep(i, k){
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << ans[c[x][y]] << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
