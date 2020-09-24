#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m, K;
string s[55];
int vis[55][55];
int ind[55][55];
int f = 1;
int id = 0;
int sz = 0;
vector<pi> cur;

bool valid(int x, int y){
	return ((x >= 0 && x < n) && (y >= 0 && y < m));
}

void dfs(int x, int y){
	sz++;
	vis[x][y] = 1;
	cur.pb({x, y});
	if(!valid(x + 1, y) || !valid(x, y + 1) || !valid(x - 1, y) || !valid(x, y - 1)){
		f = 0;
	}
	if(valid(x + 1, y) && s[x + 1][y] == '.' && !vis[x + 1][y]) dfs(x + 1, y);
	if(valid(x - 1, y) && s[x - 1][y] == '.' && !vis[x - 1][y]) dfs(x - 1, y);
	if(valid(x, y + 1) && s[x][y + 1] == '.' && !vis[x][y + 1]) dfs(x, y + 1);
	if(valid(x, y - 1) && s[x][y - 1] == '.' && !vis[x][y - 1]) dfs(x, y - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> K;
	rep(i, n) cin >> s[i];
	rep(i, 55) rep(j, 55) vis[i][j] = 0;
	rep(i, 55) rep(j, 55) ind[i][j] = -1;
	vector<pi> pos;
	rep(i, n) rep(j, m) if(s[i][j] == '.' && !vis[i][j]){
		cur.clear();
		sz = 0;
		f = 1;
		dfs(i, j);
		if(f){
			pos.pb({sz, id});
			rep(k, cur.size()) ind[cur[k].fi][cur[k].se] = id;
			id++;
		}
	}
	sort(all(pos));
	int ans = 0;
	rep(k, id - K){
		ans += pos[k].fi;
		rep(i, n) rep(j, m){
			if(ind[i][j] == pos[k].se) s[i][j] = '*';
		}
	}
	cout << ans << endl;
	rep(i, n) cout << s[i] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
