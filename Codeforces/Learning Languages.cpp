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

int n, m;
int v[100005];
vi g[100005];

void dfs(int u){
	v[u] = 1;
	for(int y : g[u]){
		if(!v[y]) dfs(y);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.in", "r", stdin);
        //freopen("output.out", "w", stdout);
	cin >> n >> m;
	int e = 0;
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		e += k;
		for(int j = 0; j < k; j++){
			int x;
			cin >> x;
			g[i].pb(n + x);
			g[n + x].pb(i);
		}
	}
	if(e == 0){
		cout << n << endl;
		return 0;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(v[i] == 0){
			dfs(i);
			ans++;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
