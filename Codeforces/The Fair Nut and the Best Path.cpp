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

ll w[300005];
ll dp[300005];
vector<pair<ll, ll>> a[300005];
ll ans = 0;

void dfs(int v, int b){
	dp[v] = w[v];
	ans = max(ans, dp[v]);
	for(auto u : a[v]){
		if(u.f == b) continue;
		dfs(u.f, v);
		ans = max(ans, dp[v] + dp[u.f] - u.s);
		dp[v] = max(dp[v], dp[u.f] + w[v] - u.s);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	for(int i = 1; i < n; i++){
		int x, y;
		ll c;
		cin >> x >> y >> c;
		a[x].pb({y, c});
		a[y].pb({x, c});
	}	
	dfs(1, 0);
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
