#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(),v.end() 
#define mp make_pair
#define pb push_back
#define f first
#define s second

int N, M;
int v[52][52];
char n[52][52];

void dfs(int a, int b, int sa, int sb){
	if(n[a][b] != n[sa][sb]){
		return;
	}
	if(v[a][b]){
		cout << "Yes" << endl;
		exit(0);
	}
	v[a][b] = 1;
	if(a - 1 > 0 && a - 1 != sa){
		dfs(a - 1, b, a, b);
	}
	if(b - 1 > 0 && b - 1 != sb){
		dfs(a, b - 1, a, b);
	}
	if(a + 1 <= N && a + 1 != sa){
		dfs(a + 1, b, a, b);
	}
	if(b + 1 <= M && b + 1 != sb){
		dfs(a, b + 1, a, b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("input.out", "w", stdout);
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> n[i][j];
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			memset(v, 0, sizeof(v));
			dfs(i, j, i, j);
		}
	}
	cout << "No" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
*/
