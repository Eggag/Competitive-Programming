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

int n, m, x, a, b;
int cat[100005];
vi g[100005];
int ans = 0;

void dfs(int c, int p, int cnt){
	if(cat[c]) cnt++;
	else cnt = 0;
	if(cnt > m) return;
	int ch = 0;
	for(int u : g[c]) if(u != p){
		ch++;
		dfs(u, c, cnt);
	}
	if(!ch) ans++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> cat[i];
	rep(i, n - 1){
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1, 0);
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
