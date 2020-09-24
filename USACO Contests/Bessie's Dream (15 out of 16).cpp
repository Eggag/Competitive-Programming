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
int g[1005][1005];
int dist[1005][1005][2][4];

bool valid(int x, int y){
	return ((x >= 0 && x < n) && (y >= 0 && y < m));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j];
	//make distance dependent on the state we are in
	//like 'smell like oranges' or 'don't smell like oranges'
	//so dist[i][j][0] or dist[i][j][1]
	set<pair<pi, pair<pi, pi>>> q;
	rep(i, n) rep(j, m) rep(k, 2) rep(l, 4) dist[i][j][k][l] = 1e9;
	dist[0][0][0][0] = 0;
	q.insert(mp(mp(0, 0), mp(mp(0, 0), mp(0, 0))));
	//fi -> dist
	//se.fi -> coords
	//se.se.fi -> smell like oranges?
	//se.se.se -> sliding?
	//transition at purples
	while(!q.empty()){
		pi cur = q.begin() -> se.fi;
		int sm = q.begin() -> se.se.fi;
		int sl = q.begin() -> se.se.se;
		int ori = q.begin() -> fi.se;
		int f = 1;
		q.erase(q.begin());
		if(sl){
			int x = cur.fi + dx[sl - 1], y = cur.se + dy[sl - 1];
			int i = sl - 1;
			if(valid(x, y) && g[x][y] != 0 && !(!sm && g[x][y] == 3)){
				//slide to it
				int sm1 = sm;
				if((!sm1 && g[x][y] == 2) || (sm1 && g[x][y] == 4)) sm1 ^= 1;
				int sl1 = sl;
				if(sl1 && g[x][y] != 4) sl1 = 0;
				f = 0;
				if(dist[x][y][sm1][i] > (dist[cur.fi][cur.se][sm][ori] + 1)){
					q.erase(mp(mp(dist[x][y][sm1][i], i), mp(mp(x, y), mp(sm1, sl1))));
					dist[x][y][sm1][i] = dist[cur.fi][cur.se][sm][ori] + 1;
					q.insert(mp(mp(dist[x][y][sm1][i], i), mp(mp(x, y), mp(sm1, sl1))));
				}
			}
			else sl = 0;
		}
		if(f){
			rep(i, 4){
				int x = cur.fi + dx[i], y = cur.se + dy[i];
				if(valid(x, y) && !(!sm && g[x][y] == 3) && g[x][y] != 0){
					int sm1 = sm;
					if((!sm1 && g[x][y] == 2) || (sm1 && g[x][y] == 4)) sm1 ^= 1;
					int sl1 = sl;
					if(!sl1 && g[x][y] == 4) sl1 = i + 1; //nice way of dealing with the direction of sliding
					if(dist[x][y][sm1][i] > (dist[cur.fi][cur.se][sm][ori] + 1)){
						q.erase(mp(mp(dist[x][y][sm1][i], i), mp(mp(x, y), mp(sm1, sl1))));
						dist[x][y][sm1][i] = dist[cur.fi][cur.se][sm][ori] + 1;
						q.insert(mp(mp(dist[x][y][sm1][i], i), mp(mp(x, y), mp(sm1, sl1))));
					}
				}
			}
		}
	}
	int mn = 1e9;
	rep(ori, 4) mn = min({mn, dist[n - 1][m - 1][0][ori], dist[n - 1][m - 1][1][ori]});
	if(mn == 1e9) mn = -1;
	cout << mn << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
