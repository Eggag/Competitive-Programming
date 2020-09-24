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

int dp[205][205][205];

void dfs(int r, int g, int b){
	if(dp[r][g][b]) return;
	dp[r][g][b] = 1;
	if(r >= 2) dfs(r - 1, g, b);
	if(g >= 2) dfs(r, g - 1, b);
	if(b >= 2) dfs(r, g, b - 1);
	if(r && g) dfs(r - 1, g - 1, b + 1);
	if(r && b) dfs(r - 1, g + 1, b - 1);
	if(b && g) dfs(r + 1, g - 1, b - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string t;
	cin >> t;
	int r = 0, g = 0, b = 0;
	for(int i = 0; i < n; i++){
		if(t[i] == 'B') b++;
		if(t[i] == 'G') g++;
		if(t[i] == 'R') r++;
	}	
	dfs(r, g, b);
	if(dp[0][0][1]) putchar('B');
	if(dp[0][1][0]) putchar('G');
	if(dp[1][0][0]) putchar('R');
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
