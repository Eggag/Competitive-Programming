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

vi g[200005];
int c[200005], pos[200005], in[200005];
int id = 0;

void dfs(int cur){
	in[id] = cur;
	pos[cur] = id++;
	c[cur] = 1;
	for(int v : g[cur]){
		dfs(v);
		c[cur] += c[v];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;
		g[x].pb(i);
	}
	dfs(1);
	for(int i = 0; i < q; i++){
		int u, k;
		cin >> u >> k;
		if(c[u] < k){
			cout << "-1" << endl;
		}
		else{
			cout << in[pos[u] + k - 1] << endl;
		}
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
