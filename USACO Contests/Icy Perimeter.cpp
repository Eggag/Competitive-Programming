#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

char g[1005][1005];
bool v[1005][1005];
int p, a;
int ma = 0;
int minp = 0;
int n;

void dfs(int x, int y){
	a++;
	v[x][y] = true;
	if((g[x + 1][y] == '.' && x + 1 <= n) || x == n) p++;
	if((g[x - 1][y] == '.' && x - 1 >= 1) || x == 1) p++;
	if((g[x][y + 1] == '.' && y + 1 <= n) || y == n) p++;
	if((g[x][y - 1] == '.' && y - 1 >= 1) || y == 1) p++;
	if(g[x + 1][y] == '#' && !v[x + 1][y] && x + 1 <= n) dfs(x + 1, y);
	if(g[x - 1][y] == '#' && !v[x - 1][y] && x - 1 >= 1) dfs(x - 1, y);
	if(g[x][y + 1] == '#' && !v[x][y + 1] && y + 1 <= n) dfs(x, y + 1);
	if(g[x][y - 1] == '#' && !v[x][y - 1] && y - 1 >= 1) dfs(x, y - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("perimeter.in", "r", stdin);
        freopen("perimeter.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> g[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(v[i][j] || g[i][j] == '.'){
				continue;
			}
			a = 0;
			p = 0;
			dfs(i, j);
			if(a > ma){
				ma = a;
				minp = p;
			}
			if(a == ma){
				minp = min(minp, p);
			}						
		}
	}
	cout << ma << " " << minp << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
