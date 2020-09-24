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

int c[100005];
vi g[100005];
bool vis[100005];
int n;

bool dfs(int cur){
	vis[cur] = 1;
	for(int x : g[cur]){
		if(vis[x]) continue;
		if(c[cur] != c[x]){ return false; }
		if(!dfs(x)){ return false; }
	}
	return true;
}

void check(int v){
	fill(vis, vis + n + 5, 0);
	vis[v] = 1;
	for(int y : g[v]){
		if(!dfs(y)){ return; }
	}
	cout << "YES" << endl << v << endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	for(int i = 1; i <= n; i++){
		for(int a : g[i]){
			if(c[i] != c[a]){
				check(i);
				check(a);
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	check(1);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
