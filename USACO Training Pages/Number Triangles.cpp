/*
ID: egor_ga1
PROG: numtri
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define mp make_pair
#define pb push_back
#define f first
#define s second

int b[1001][1001];
int dp[1001][1001];
bool v[1001][1001];

int dfs(int x, int y, int z){
	if(v[x][y]){
		return dp[x][y];
	}
	v[x][y] = 1;
	if(x <= z){
		return dp[x][y] = b[x][y] + max(dfs(x + 1, y, z), dfs(x + 1, y + 1, z));
	}
	else{
		return 0;
	}
}

int main(){
	freopen("numtri.in", "r", stdin);
        freopen("numtri.out", "w", stdout);
	int r;
	cin >> r;
	for(int i = 1; i <= r; i++){
		for(int a = 1; a <= i; a++){
			cin >> b[i][a];	
		}
	}
	cout << dfs(1, 1, r) << endl;
}
