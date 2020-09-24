#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int g[25][25];

int dfs(int x, int y, int d, int c, int res){
	if(c == 4) return res;
	res *= g[x][y];
	if(d == 0) dfs(x + 1, y, d, c + 1, res);
	if(d == 1) dfs(x, y + 1, d, c + 1, res);
	if(d == 2) dfs(x + 1, y + 1, d, c + 1, res);
}

int dfs1(int x, int y, int d, int c, int res){
	if(c == 4) return res;
	res *= g[x][y];
	if(d == 0) dfs1(x + 1, y, d, c + 1, res);
	if(d == 1) dfs1(x, y - 1, d, c + 1, res);
	if(d == 2) dfs1(x + 1, y - 1, d, c + 1, res);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("1.txt", "r", stdin);
	//freopen("output.out", "w", stdout);
	memset(g, 0, sizeof(g));
	rep(i, 20) rep(j, 20){
		cin >> g[i][j];
	}
	int ans = 0;
	rep(i, 17) rep(j, 17){
		rep(k, 3){
			ans = max(ans, dfs(i, j, k, 0, 1));
		}
	}
	rep(i, 17) for(int j = 16; j >= 3; j--){
		rep(k, 3){
			ans = max(ans, dfs1(i, j, k, 0, 1));
		}
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
