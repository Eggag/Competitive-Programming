#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

vi g[105];
int d[105];

void dfs(int c, int p, int dist){
	d[c] = dist;
	for(int u : g[c]) if(u != p){
		dfs(u, c, dist + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	int ans = 0;
	while(q--){
		int n;
		cin >> n;
		rep(i, n) g[i].clear();
		rep(i, n - 1){
			int a, b;
			cin >> a >> b;
			a--, b--;
			g[a].pb(b);
			g[b].pb(a);
		}
		int res = 0;
		rep(i, n){
			dfs(i, -1, 0);
			rep(i, n) if(d[i] > res) res = d[i];
		}
		ans += res;
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
