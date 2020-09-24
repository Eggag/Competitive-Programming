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

vi c[100005];
bool visit[100005];
int ind[100005];
int dp[100005];

void dfs(int x){
	visit[x] = true;
	for(int y : c[x]){
		dp[y] = max(dp[y], dp[x] + 1);
		ind[y]--;
		if(ind[y] == 0){
			dfs(y);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		c[a].pb(b);
		ind[b]++;
	}	
	for(int i = 1; i <= n; i++){
		if(!visit[i] && !ind[i]){
			dfs(i);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, dp[i]);
	}
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
