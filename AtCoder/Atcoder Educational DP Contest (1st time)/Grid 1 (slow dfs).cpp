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

int h, w;
char g[1005][1005];
ll ans = 0;

void dfs(int y, int x){
	if(y == h && x == w){
		ans++;
		return;
	}
	if(g[y + 1][x] != '#' && y + 1 <= h) dfs(y + 1, x);
	if(g[y][x + 1] != '#' && x + 1 <= w) dfs(y, x + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	cin >> h >> w;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			cin >> g[i][j];
		}
	}
	dfs(1, 1);
	ll MOD = 1e9 + 7;
	cout << ans % MOD << endl;	
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
