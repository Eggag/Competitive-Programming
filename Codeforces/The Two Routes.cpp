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

const int INF = 1e9;
int g[405][405];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			g[i][j] = ((i == j) ? 0 : INF);
		}
	}
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a][b] = g[b][a] = 1;
	}
	if(g[1][n] == 1){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i != j) g[i][j] = INF + 1 - g[i][j];
			}
		}	
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	if(g[1][n] == INF){
		cout << "-1" << endl;
	}
	else{
		cout << g[1][n] << endl;
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
