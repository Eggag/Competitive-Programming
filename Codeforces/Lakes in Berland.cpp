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

int n, m, k;
int N = 0;
int cnt;
string g[55];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
pair<int, pi> a[55 * 55];
int v[55][55];

bool check_cell(int x, int y){
	if(x < 0 || y < 0 || x > (n - 1) || y > (m - 1)) return false;
	return (g[x][y] == '.');
}

void dfs(int x, int y){
	v[x][y] = 1;
	cnt++;
	for(int i = 0; i < 4; i++){
		int a = x + dx[i], b = y + dy[i];
		if(!check_cell(a, b) || v[a][b]) continue;
		dfs(a, b);
	}
	return;
}

void dfs2(int x, int y){
	g[x][y] = '*';
	for(int i = 0; i < 4; i++){
		int a = x + dx[i], b = y + dy[i];
		if(!check_cell(a, b)) continue;
		dfs2(a, b);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> g[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i > 0 && i < (n - 1) && j > 0 && j < (m - 1)) continue;
			if(g[i][j] == '*') continue;
			if(v[i][j]) continue;
			dfs(i, j);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(g[i][j] == '*') continue;
			if(v[i][j]) continue;
			cnt = 0;
			dfs(i, j);
			a[N++] = mp(cnt, mp(i, j));		
		}
	}
	sort(a, a + N);
	int ans = 0;
	for(int i = 0; i < (N - k); i++){
		ans += a[i].f;
		dfs2(a[i].s.f, a[i].s.s);
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++){
		cout << g[i] << endl;
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
