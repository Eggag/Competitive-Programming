#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
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
const int mxN = 205;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
string c[mxN];
int vis[mxN][mxN];

bool valid(int i, int j){
	return (i >= 0 && i < n && j >= 0 && j < n);
}

void inv(int i, int j){
	if(c[i][j] == '1') c[i][j] = '0';
	else c[i][j] = '1';
}

void solve(){
	cin >> n;
	rep(i, n) cin >> c[i];
	int mn = 2;
	vector<pi> ans;
	rep(i, 1 << 4){
		if(i & 1) inv(1, 0);
		if(i & 2) inv(0, 1);
		if(i & 4) inv(n - 2, n - 1);
		if(i & 8) inv(n - 1, n - 2);
		//now we just bfs from the 2 upper vertices
		memset(vis, 0, sizeof(vis));
		queue<pair<pi, char>> q;
		q.push(mp(mp(1, 0), c[1][0]));
		q.push(mp(mp(0, 1), c[0][1]));
		vis[0][1] = vis[1][0] = 1;
		while(!q.empty()){
			pair<pi, char> cur = q.front();
			pi co = cur.fi;
			q.pop();
			rep(j, 4){
				int x = co.fi + dx[j], y = co.se + dy[j];
				if(valid(x, y) && !vis[x][y] && (c[x][y] == 'F' || cur.se == c[x][y])){
					vis[x][y] = 1;
					q.push(mp(mp(x, y), cur.se));
				}
			}
		}
		if(!vis[n - 1][n - 1]){
			int nw = __builtin_popcount(i);
			if(nw <= mn){
				mn = nw;
				ans.clear();
				if(i & 1) ans.pb({1, 0});
				if(i & 2) ans.pb({0, 1});
				if(i & 4) ans.pb({n - 2, n - 1});
				if(i & 8) ans.pb({n - 1, n - 2});
			}
		}
		if(i & 1) inv(1, 0);
		if(i & 2) inv(0, 1);
		if(i & 4) inv(n - 2, n - 1);
		if(i & 8) inv(n - 1, n - 2);
	}
	cout << mn << endl;
	for(pi x : ans) cout << x.fi + 1 << " " << x.se + 1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
