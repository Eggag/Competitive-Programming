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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
char g[55][55];
int vis[55][55];

bool valid(int x, int y){
	return (x >= 0 && y >= 0 && x < n && y < m);
}

void solve(){
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j];
	rep(i, n) rep(j, m){
		//check for adjacent G and B (which is a nono)
		rep(k, 4){
			int x = i + dx[k], y = j + dy[k];
			if(valid(x, y)){
				string s = "";
				s += g[i][j];
				s += g[x][y];
				sort(all(s));
				if(s == "BG"){
					cout << "No" << endl;
					return;
				}
			}
		}
	}
	rep(i, n) rep(j, m) if(g[i][j] == 'B'){
		//it needs to be surrounded
		rep(k, 4){
			int x = i + dx[k], y = j + dy[k];
			if(valid(x, y) && g[x][y] == '.') g[x][y] = '#';
		}
	}
	rep(i, n) rep(j, m) vis[i][j] = 0;
	queue<pi> q;
	if(g[n - 1][m - 1] != '#'){
		q.push({n - 1, m - 1});
		vis[n - 1][m - 1] = 1;
	}
	while(!q.empty()){
		pi cur = q.front();
		q.pop();
		int i = cur.fi, j = cur.se;
		rep(k, 4){
			int x = i + dx[k], y = j + dy[k];
			if(valid(x, y) && g[x][y] != '#' && !vis[x][y]){
				vis[x][y] = 1;
				q.push({x, y});
			}
		}
	}
	rep(i, n) rep(j, m){
		if(g[i][j] == 'B' && vis[i][j]){
			cout << "No" << endl;
			return;
		}
		if(g[i][j] == 'G' && !vis[i][j]){
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
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
