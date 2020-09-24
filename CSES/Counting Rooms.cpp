#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
string g[1005];
int v[1005][1005];

void dfs(int i, int j){
	if(v[i][j]) return;
	v[i][j] = 1;
	if(i + 1 < n && g[i + 1][j] == '.') dfs(i + 1, j);
	if(i - 1 >= 0 && g[i - 1][j] == '.') dfs(i - 1, j);
	if(j + 1 < m && g[i][j + 1] == '.') dfs(i, j + 1);
	if(j - 1 >= 0 && g[i][j - 1] == '.') dfs(i, j - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> g[i];
	rep(i, 1005) rep(j, 1005) v[i][j] = 0;
	int ans = 0;
	rep(i, n) rep(j, m) if(!v[i][j] && g[i][j] == '.'){
		dfs(i, j);
		ans++;
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
