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

int cnt = 0;
int all = 0;
char g[505][505];
int v[505][505];
int n, m, k;

void dfs(int x, int y){
	if(v[x][y]) return;
	if(all == cnt - k) return;
	v[x][y] = 1;
	all++;
	if(x && g[x - 1][y] == '.') dfs(x - 1, y);
	if(y && g[x][y - 1] == '.') dfs(x, y - 1);
	if(x < n - 1 && g[x + 1][y] == '.') dfs(x + 1, y);
	if(y < m - 1 && g[x][y + 1] == '.') dfs(x, y + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, n) rep(j, m){
		cin >> g[i][j];
		if(g[i][j] == '.') cnt++;
	}
	rep(i, n) rep(j, m){
		if(g[i][j] == '.'){
			dfs(i, j);
			rep(a, n){
				rep(b, m){
					if(!v[a][b] && g[a][b] == '.') g[a][b] = 'X';
					cout << g[a][b];
				}
				cout << endl;
			}
			return 0;
		}
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
