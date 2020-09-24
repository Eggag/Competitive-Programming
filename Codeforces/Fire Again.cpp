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
int vis[2005][2005];
int dist[2005][2005];

bool valid(int x, int y){
	return (x >= 0 && y >= 0 && x < n && y < m);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	int k;
	cin >> k;
	queue<pi> q;
	rep(i, 2005) rep(j, 2005) dist[i][j] = 1e9;
	rep(i, k){
		int a, b;
		cin >> a >> b;
		a--, b--;
		vis[a][b] = 1;
		dist[a][b] = 0;
		q.push({a, b});
	}
	while(!q.empty()){
		pi cur = q.front();
		q.pop();
		rep(i, 4){
			int x = cur.fi + dx[i], y = cur.se + dy[i];
			if(valid(x, y) && !vis[x][y]){
				vis[x][y] = 1;
				q.push({x, y});
				dist[x][y] = dist[cur.fi][cur.se] + 1;
			}
		}
	}
	int mx = 0;
	pi bst = {-1, -1};
	rep(i, n) rep(j, m){
		if(dist[i][j] >= mx){
			bst = {i, j};
			mx = dist[i][j];
		}
	}
	cout << bst.fi + 1 << " " << bst.se + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
