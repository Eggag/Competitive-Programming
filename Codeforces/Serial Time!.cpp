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

string g[15][15];
int v[15][15][15];

int n, m, k;
int ans = 0;

void dfs(int x, int y, int z){
	if(x < 0 || x >= k) return;
	if(y < 0 || y >= n) return;
	if(z < 0 || z >= m) return;
	if(g[x][y][z] == '#') return;
	if(v[x][y][z]) return;
	v[x][y][z] = 1;
	ans++;
	dfs(x + 1, y, z);
	dfs(x, y + 1, z);
	dfs(x, y, z + 1);
	dfs(x - 1, y, z);
	dfs(x, y - 1, z);
	dfs(x, y, z - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	memset(v, 0, sizeof(v));
	cin >> k >> n >> m;
	rep(i, k){
		rep(j, n){
			cin >> g[i][j];
		}
	}
	int a, b;
	cin >> a >> b;
	a--, b--;
	dfs(0, a, b);
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
