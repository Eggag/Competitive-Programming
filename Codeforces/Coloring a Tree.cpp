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

vi g[10005];
int c[10005];
int ans = 0;

void dfs(int cur, int p){
	if(c[cur] != c[p]){
		ans++;
	}
	for(int v : g[cur]){
		if(v == p) continue;
		dfs(v, cur);
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
	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		g[i].pb(x);
		g[x].pb(i);
	}
	c[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
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
