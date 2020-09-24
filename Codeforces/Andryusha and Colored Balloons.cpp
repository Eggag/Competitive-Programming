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
int q[200005];

void dfs(int c, int p){
	int n = 1;
	for(int v : g[c]){
		if(v == p) continue;
		while(n == q[c] || n == q[p]) n++;
		q[v] = n;
		n++;
		dfs(v, c);
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
	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, (int)( 1 + g[i].size()));
	}
	cout << ans << endl;
	q[1] = 1;
	dfs(1, 1);
	for(int i = 1; i <= n; i++){
		cout << q[i] << " ";
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
