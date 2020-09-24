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

int n, m;
string s[1005];
int ans[1000005];
int c[1005][1005];
int vis[1005][1005];
int comp = 0;

void dfs(int i, int j){
	vis[i][j] = 1;
	c[i][j] = comp;
	ans[comp]++;
	if((i + 1) < n && s[i + 1][j] == '.' && !vis[i + 1][j]) dfs(i + 1, j);
	if((i - 1) >= 0 && s[i - 1][j] == '.' && !vis[i - 1][j]) dfs(i - 1, j);
	if((j + 1) < m && s[i][j + 1] == '.' && !vis[i][j + 1]) dfs(i, j + 1);
	if((j - 1) >= 0 && s[i][j - 1] == '.' && !vis[i][j - 1]) dfs(i, j - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	memset(ans, 0, sizeof(ans));
	memset(vis, 0, sizeof(vis));
	rep(i, n) rep(j, m) if(!vis[i][j] && s[i][j] == '.'){
		dfs(i, j);
		comp++;
	}
	/*
	rep(i, n){
		rep(j, m){
			if(s[i][j] == '*') cout << s[i][j];
			else cout << ans[c[i][j]];
		}
		cout << endl;
	}
	*/
	rep(i, n){
		rep(j, m){
			if(s[i][j] == '.') cout << s[i][j];
			else{
				int cur = 1;
				set<int> comps;
				if((i + 1) < n && s[i + 1][j] == '.') comps.insert(c[i + 1][j]);
				if((i - 1) >= 0 && s[i - 1][j] == '.') comps.insert(c[i - 1][j]);
				if((j + 1) < m && s[i][j + 1] == '.') comps.insert(c[i][j + 1]);
				if((j - 1) >= 0 && s[i][j - 1] == '.') comps.insert(c[i][j - 1]);
				for(auto x : comps) cur += ans[x];
				cout << cur % 10;
			}
		}
		cout << endl;
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
