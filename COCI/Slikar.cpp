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

int r, c;
int dist[55][55], vis[55][55], dist1[55][55];

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < r && j < c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> r >> c;
	vector<string> s(r);
	rep(i, r) cin >> s[i];
	pi S, D;
	vector<pi> ST;
	rep(i, r) rep(j, c){
		if(s[i][j] == 'S') S = mp(i, j);
		if(s[i][j] == 'D') D = mp(i, j);
		if(s[i][j] == '*') ST.pb(mp(i, j));
	}
	rep(i, 55) rep(j, 55) dist[i][j] = 1e9;
	queue<pi> q;
	rep(i, ST.size()){
		dist[ST[i].fi][ST[i].se] = 0;
		vis[ST[i].fi][ST[i].se] = 1;
		q.push(ST[i]);
	}
	while(!q.empty()){
		pi cur = q.front();
		q.pop();
		rep(i, 4){
			int x = cur.fi + dx[i], y = cur.se + dy[i];
			if(valid(x, y) && !vis[x][y] && s[x][y] != 'D' && s[x][y] != 'X'){
				dist[x][y] = dist[cur.fi][cur.se] + 1;
				vis[x][y] = 1;
				q.push(mp(x, y));
			}
		}
	}
	rep(i, 55) rep(j, 55) vis[i][j] = 0;
	rep(i, 55) rep(j, 55) dist1[i][j] = 1e9;
	q.push(S);
	vis[S.fi][S.se] = 1;
	dist1[S.fi][S.se] = 0;
	while(!q.empty()){
		pi cur = q.front();
		q.pop();
		rep(i, 4){
			int x = cur.fi + dx[i], y = cur.se + dy[i];
			if(valid(x, y) && !vis[x][y] && (dist1[cur.fi][cur.se] + 1) < (dist[x][y]) && s[x][y] != 'X'){
				dist1[x][y] = dist1[cur.fi][cur.se] + 1;
				vis[x][y] = 1;
				q.push(mp(x, y));
			}
		}
	}
	if(dist1[D.fi][D.se] != 1e9) cout << dist1[D.fi][D.se] << endl;
	else cout << "KAKTUS" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
