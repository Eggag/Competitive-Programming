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

string hor, vert;
int v[25][25];
int cnt[25][25];
int n, m;

void dfs(int x, int y){
	if(!v[x][y]) return;
	v[x][y] = 0;
	cnt[x][y]++;
	int d, d1;
	if(hor[x - 1] == '>'){
		d = 1;
	}
	else{
		d = -1;
	}
	if(vert[y - 1] == '^'){
		d1 = -1;
	}
	else{
		d1 = 1;
	}
	if(x + d1 >= 1 && x + d1 <= n) dfs(x + d1, y);
	if(y + d >= 1 && y + d <= m) dfs(x, y + d);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	memset(cnt, 0, sizeof(cnt));
	cin >> n >> m;
	cin >> hor >> vert;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			memset(v, 1, sizeof(v));
			dfs(i, j);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(cnt[i][j] != (n * m)){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
